import sys
sys.setrecursionlimit(10**6)

t = int(input())
ans = []

def dfs(x, y):
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False
    if graph[x][y] == 1:
        graph[x][y] = 0
        dfs(x - 1, y)
        dfs(x + 1, y)
        dfs(x, y - 1)
        dfs(x, y + 1)

        return True
    return False

for i in range(t):
    n, m, k = map(int, input().split())
    graph = [[0] * m for _ in range(n)]
    
    for i in range(k):
        x, y = map(int, input().split())
        graph[x][y] = 1

    result = 0
    for i in range(n):
        for j in range(m):
            if dfs(i, j) == True:
                result += 1

    ans.append(result)

for i in range(t):
    print(ans[i])
