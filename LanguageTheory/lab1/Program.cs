using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;

public class Lab1 {
    static public void Main () {
        new Solver ().solve ();
    }
}

public class Solver {

    public class Node {
        public int level = 1;
        public string op;
        public Node left;
        public Node right;
        public Node (string op, int level, Node left = null, Node right = null) {
            this.op = op;
            this.level = level;
            this.left = left;
            this.right = right;
        }
    }
    private Dictionary<string, string> nameTable = new Dictionary<string, string> ();

    public void solve () {
        StreamWriter writer = new StreamWriter(new FileStream("OUTPUT.TXT", FileMode.OpenOrCreate, FileAccess.Write));
        Console.SetOut(writer);
        string exp = new StreamReader ("INPUT.TXT").ReadLine ();
        Console.WriteLine ("---Expression---");
        Console.WriteLine (exp);

        Console.WriteLine ("\n---Tree---");
        Node root = buildTree (parseExpressionItems (exp));
        dumpTree (root);

        Console.WriteLine ("\n---Names table---");
        foreach (KeyValuePair<string, string> entry in this.nameTable) {
            Console.WriteLine (entry.Key + ": " + entry.Value);
        }

        Console.WriteLine ("\n---Non-optimized code---");
        List<string[]> codes = buildCodes (root);
        foreach (string[] code in codes) {
            Console.WriteLine (code[0] + " " + code[1]);
        }

        Console.WriteLine ("\n---Optimized code---");
        foreach (string[] code in optimizeCodes (codes)) {
            Console.WriteLine (code[0] + " " + code[1]);
        }
        writer.Close();
    }

    private Node buildTree (string[] exp, int level = 0) {
        int maxPos = -1;
        int maxPriority = -1;
        int opened = 0;
        for (int i = 0; i < exp.Length; i++) {
            if (exp[i] == "(" || exp[i] == ")") {
                opened += exp[i] == "(" ? 1 : -1;
            }
            if (opened == 0 && isOperator (exp[i])) {
                int priority = getOperatorPriority (exp[i]);
                if (priority > maxPriority) {
                    maxPriority = priority;
                    maxPos = i;
                }
            }
        }

        Node node = new Node (exp[0], level);
        if (maxPos != -1) {
            node = new Node (
                exp[maxPos], level,
                buildTree (slice (exp, 0, maxPos), level + 1),
                buildTree (slice (exp, maxPos + 1), level + 1)
            );
        } else if (exp[0] == "(") {
            node = buildTree (slice (exp, 1, exp.Length - 1), level);
        }
        if (!isOperator (node.op)) {
            this.nameTable.Add (node.op, getValueType (node.op));
        }
        return node;
    }

    private List<string[]> buildCodes (Node root) {
        List<string[]> result = new List<string[]> ();
        if (!isOperator (root.op)) {
            result.Add (new string[] { "LOAD", (this.nameTable.GetValueOrDefault (root.op) == "Identifier" ? root.op : ("=" + root.op)) });
        }
        if (root.left != null) {
            buildCodes (root.left);
        }
        if (root.right != null) {
            buildCodes (root.right);
        }
        if (root.op == "+") {
            result.AddRange (buildCodes (root.right));
            result.Add (new string[] { "STORE", "$" + root.level });
            result.AddRange (buildCodes (root.left));
            result.Add (new string[] { "ADD", "$" + root.level });
        }
        if (root.op == "*") {
            result.AddRange (buildCodes (root.right));
            result.Add (new string[] { "STORE", "$" + root.level });
            result.AddRange (buildCodes (root.left));
            result.Add (new string[] { "MPY", "$" + root.level });
        }
        if (root.op == "=") {
            result.AddRange (buildCodes (root.right));
            result.Add (new string[] { "STORE", root.left.op });
        }
        return result;
    }

    private List<string[]> optimizeCodes (List<string[]> codes) {
        codes = optimizeFirstStep (codes);
        codes = optimizeSecondStep (codes);
        return optimizeThirdStep (codes);
    }

    private List<string[]> optimizeFirstStep (List<string[]> codes) {
        int startIdx = 0;
        while (startIdx < codes.Count) {
            int loadCodeIdx = codes.FindIndex (startIdx, (code) => { return code[0] == "LOAD"; });
            if (loadCodeIdx == -1) {
                break;
            }
            int opCodeIdx = codes.FindIndex (loadCodeIdx + 1, (code) => { return code[0] == "ADD" || code[0] == "MPY"; });
            if (opCodeIdx == -1) {
                break;
            }
            if (loadCodeIdx + 1 == opCodeIdx) {
                int addCodesCount = codes.FindAll ((code) => { return code == codes[opCodeIdx]; }).Count;
                if (addCodesCount == 1) {
                    string[] loadCode = new string[] { "LOAD", codes[opCodeIdx][1] };
                    string[] opCode = new string[] { codes[opCodeIdx][0], codes[loadCodeIdx][1] };
                    codes.RemoveAt (loadCodeIdx);
                    codes.Insert (loadCodeIdx, loadCode);
                    codes.RemoveAt (opCodeIdx);
                    codes.Insert (opCodeIdx, opCode);
                }
                startIdx = opCodeIdx;
                continue;
            }
            startIdx++;
        }
        return codes;
    }

    private List<string[]> optimizeSecondStep (List<string[]> codes) {
        int startIdx = 0;
        while (startIdx < codes.Count) {
            int storeCodeIdx = codes.FindIndex (startIdx, (code) => { return code[0] == "STORE"; });
            if (storeCodeIdx == -1) {
                break;
            }
            int loadCodeIdx = codes.FindIndex (storeCodeIdx, (code) => { return code[0] == "LOAD"; });
            if (loadCodeIdx == -1) {
                break;
            }
            if (storeCodeIdx + 1 == loadCodeIdx && codes[storeCodeIdx][1] == codes[loadCodeIdx][1]) {
                int followingUsage = codes.FindIndex (loadCodeIdx, (code) => { return code[1] == codes[loadCodeIdx][1]; });
                bool isUsedFurther = followingUsage != -1;
                bool canBeOptimized = false;
                if (isUsedFurther) {
                    int nextLoadIdx = codes.FindIndex (loadCodeIdx, (code) => { return code == codes[loadCodeIdx]; });
                    if (nextLoadIdx != -1) {
                        canBeOptimized = true;
                    }
                } else {
                    canBeOptimized = true;
                }
                if (canBeOptimized) {
                    codes.RemoveAt (loadCodeIdx);
                    codes.RemoveAt (storeCodeIdx);
                }
                startIdx = loadCodeIdx;
                continue;
            }
            startIdx++;
        }
        return codes;
    }

    private List<string[]> optimizeThirdStep (List<string[]> codes) {
        int startIdx = 0;
        while (startIdx < codes.Count) {
            int loadCodeIdx = codes.FindIndex (startIdx, (code) => { return code[0] == "LOAD"; });
            if (loadCodeIdx == -1) {
                break;
            }
            int storeCodeIdx = codes.FindIndex (loadCodeIdx, (code) => { return code[0] == "STORE"; });
            if (storeCodeIdx == -1) {
                break;
            }
            if (storeCodeIdx == loadCodeIdx + 1) {
                int nextLoadIdx = codes.FindIndex (storeCodeIdx, (code) => { return code[0] == "LOAD"; });
                if (storeCodeIdx + 1 == nextLoadIdx) {
                    int nextStoreIdx = codes.FindIndex (nextLoadIdx, (code) => { return code == codes[storeCodeIdx]; });
                    for (int i = storeCodeIdx + 1; i < (nextStoreIdx == -1 ? codes.Count : nextStoreIdx); i++) {
                        if (codes[i][1] == codes[storeCodeIdx][1]) {
                            codes.Insert (i, new string[] { codes[i][0], codes[loadCodeIdx][1] });
                            codes.RemoveAt (i + 1);
                        }
                    }
                    codes.RemoveAt (storeCodeIdx);
                    codes.RemoveAt (loadCodeIdx);
                }
                startIdx = storeCodeIdx;
            }
            startIdx++;
        }
        return codes;
    }

    private void dumpTree (Node root) {
        for (int i = 0; i < root.level; i++) {
            Console.Write ("    |");
        }
        Console.WriteLine ("");

        if (root.left != null) {
            dumpTree (root.left);
        }
        for (int i = 0; i < root.level; i++) {
            Console.Write ("    |");
        }
        Console.WriteLine (root.op + (root.left != null || root.right != null ? "---|" : ""));
        if (root.right != null) {
            dumpTree (root.right);
        }
    }

    private bool isOperator (string op) {
        return op == "=" || op == "+" || op == "*";
    }

    private string[] slice (string[] array, int start, int length = 0) {
        List<string> res = new List<string> ();
        for (int i = start; i < (length == 0 ? array.Length : length); i++) {
            res.Add (array[i]);
        }
        return res.ToArray ();
    }

    private int getOperatorPriority (string op) {
        switch (op) {
            case "=":
                return 3;
            case "+":
                return 1;
            case "*":
                return 2;
        }
        return 0;
    }

    private string getValueType (string op) {
        if (tryRegex (op, @"(\d+\.\d+)|(\d+[eE][+-]\d+)")) {
            return "Float";
        }
        if (tryRegex (op, @"\d+")) {
            return "Int";
        }
        if (tryRegex (op, @"(\w[\w\d]*)")) {
            return "Identifier";
        }
        return "Unknown";
    }

    private bool tryRegex (string str, string regex) {
        return new Regex (regex).Matches (str).Count > 0;
    }

    private string[] parseExpressionItems (string exp) {
        Regex regex = new Regex (@"(((\d+\.\d+)|(\d+[eE][+-]\d+)|(\w[\w\d]*)|\d+)|[()=+*])");
        MatchCollection mc = regex.Matches (exp);
        string[] matches = new string[mc.Count];
        for (int i = 0; i < matches.Length; i++) {
            matches[i] = mc[i].ToString ();
        }
        return matches;
    }
}
