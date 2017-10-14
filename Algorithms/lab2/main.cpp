#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

string find_path(int size, bool* visited, int** graph, int node1, int node2, string current_path = "") {
    visited[node1] = true;
    if (node1 == node2) {
        return current_path;
    }
    for (int i = 0; i < size; ++i)
    {
        int next = graph[node1][i];
        if (next != 0) {
            string path = find_path(size, visited, graph, i, node2, current_path + " > " + to_string(i + 1));
            if (path != "") {
                return path;
            }
        }
    }

    return "";
}

int main()
{
    int n1, n2;
    printf("Enter first node:");
    scanf("%d", &n1);
    printf("Enter second node:");
    scanf("%d", &n2);

    ifstream stream("graph.txt");
    int size;
    stream >> size;

    int** graph = new int*[size];
    for (int i = 0; i < size; ++i)
    {
        graph[i] = new int[size];
    }
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            stream >> graph[i][j];
        }
    }
    bool* visited = new bool[size];
    string path = find_path(size, visited, graph, n1 - 1, n2 - 1);
    if (path == "") {
        cout << "There is no path";
    } else {
        cout << "Path is: " << n1 << path << "\n";
    }

    free(graph);
    free(visited);
    return 0;
}