import Queue

def BFS(start):
    q = Queue()
    q.put(start)
    visited[start] = 1

    while not q.empty():
        v = q.get()
        print(" -->", v, end="")
        for i in range(n):
            if not visited[i] and graph[v][i] == 1:
                q.put(i)
                visited[i] = 1

def DFS(x, visited):
    if visited[x] == 1:
        return
    visited[x] = 1
    print("--->", x, end=" ")
    for i in range(n):
        if graph[x][i] == 1 and visited[i] != 1:
            DFS(i, visited)

n = int(input("Enter number of vertices: "))
graph = [[0 for i in range(n)] for i in range(n)]

for i in range(n):
    for j in range(i + 1, n):
        graph[i][j] = int(input(f"Enter 1 if edge is present in between graph[{i}][{j}]: "))
        graph[j][i] = graph[i][j]

for i in range(n):
    for j in range(n):
        print(graph[i][j], end=" ")
    print("\n")

visited = n * [0]

for i in range(n):
    if not visited[i]:
        DFS(i, visited)

visited = n * [0]

print("\n")

for j in range(n):
    if not visited[j]:
        BFS(j)