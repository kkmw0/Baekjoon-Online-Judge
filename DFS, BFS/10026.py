import sys
sys.setrecursionlimit(10**6)

n = int(input())
graph = []
colors = ['R', 'B', 'G']

for i in range(n):
    graph.append(list(input()))

def dfs(x, y, color, chk):
    if x <= -1 or x >= n or y <= -1 or y >= n:
        return False

    if graph[x][y] == color and chk[x][y] == 0:
        chk[x][y] = 1
        dfs(x - 1, y, color, chk)
        dfs(x + 1, y, color, chk)
        dfs(x, y - 1, color, chk)
        dfs(x, y + 1, color, chk)
        return True
    return False

# 적록색약 x
result1 = 0
for color in colors:
    chk = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if dfs(i, j, color, chk) == True:
                result1 += 1

for i in range(n):
    for j in range(n):
        if graph[i][j] == 'G':
            graph[i][j] = 'R'

# 작록색약 o
colors.pop()
result2 = 0
for color in colors:
    chk = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if dfs(i, j, color, chk) == True:
                result2 += 1 

print(result1, result2)
    


