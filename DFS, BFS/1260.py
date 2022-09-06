import sys
from collections import deque
sys.setrecursionlimit(10**6)

n, m, start = map(int, input().split())

graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, n + 1):
    graph[i].sort()

def dfs(graph, v, visited):
    visited[v] = True
    print(v, end = ' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True

    while queue:
        v = queue.popleft()
        print(v, end = ' ')

        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

dfs(graph, start, visited)
print()
visited = [False] * (n + 1)
bfs(graph, start, visited)
