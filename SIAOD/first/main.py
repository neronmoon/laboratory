# noinspection PyInterpreter
class Tree:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def add(self, node):
        if node.data < self.data:
            self.left = node
        else:
            self.right = node


def init_tree():
    root = Tree(5)

    first_subtree = Tree(4)
    first_subtree.add(Tree(12))
    first_subtree.add(Tree(3))



    fourth_subtree = Tree(45)
    fourth_subtree.add(Tree(100))


    five_subtree = Tree(45)
    five_subtree.add(Tree(100))
    five_subtree.add(Tree(0))

    fourth_subtree.add(five_subtree)

    second_subtree = Tree(45)
    second_subtree.add(Tree(100))
    second_subtree.add(fourth_subtree)

    root.add(first_subtree)
    root.add(second_subtree)

    return root


def print_tree(root, level=0):
    print("  " * level, root.data)
    if root.left:
        print_tree(root.left, level + 1)
    if root.right:
        print_tree(root.right, level + 1)


def dfs(node, sum=0, count=0):
    if node.left == None and node.right == None:  # this node is list
        return sum, count
    children_sum = 0
    children_count = 0
    if node.left:
        left_sum, left_count = dfs(node.left, sum, count)
        children_sum += left_sum
        children_count += 1
    if node.right:
        right_sum, right_count = dfs(node.right, sum, count)
        children_sum += right_sum
        children_count += 1

    return sum + node.data + children_sum, count + children_count + 1


def main():
    tree = init_tree()
    sum, count = dfs(tree)
    print(sum / count)
    print_tree(tree)


main()
