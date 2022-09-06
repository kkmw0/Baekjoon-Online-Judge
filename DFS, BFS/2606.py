import sys
sys.setrecursionlimit(10**6)

n = int(input())
m = int(input())

graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(graph, v, visited):
    global cnt
    visited[v] = True
    for i in graph[v]:
        if not visited[i]:
            cnt += 1
            dfs(graph, i, visited)

cnt = 0
dfs(graph, 1, visited)

print(cnt)
