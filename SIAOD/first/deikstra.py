def init_graph():
    graph = []
    with open("graph.txt", "r") as f:
        lines = f.readlines()
        for line in lines:
            strings = line.strip().split(" ")
            graph.append(list(map(int, strings)))
    return graph


def bfs(graph, dest):
    queue = [0]
    visited = []
    p = [-1, 0, 0, 0, 0]
    while len(queue) > 0:
        vertex = queue.pop()
        visited.append(vertex)
        for to, has_path in enumerate(graph[vertex]):
            if to not in visited and has_path != 0:
                queue.insert(0, to)
                p[to] = vertex
    if dest not in visited:
        return "No Path"
    else:
        path = []
        v = dest
        while v != -1:
            path.append(v)
            v = p[v]
        return path


def main():
    graph = init_graph()
    dest = int(input("Enter 0-4 dest vertex: "))

    print(bfs(graph, dest))


main()
