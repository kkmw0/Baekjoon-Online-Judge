import sys
sys.setrecursionlimit(10**6)

n = int(input())
array = []

for i in range(n):
    array.append(list(map(int, input().split())))

def dfs(x, y, h, chk):
    if x <= -1 or x >= n or y <= -1 or y >= n:
        return False

    if array[x][y] > h and chk[x][y] == 0:
        chk[x][y] = 1
        dfs(x - 1, y, h, chk)
        dfs(x + 1, y, h, chk)
        dfs(x, y - 1, h, chk)
        dfs(x, y + 1, h, chk)
        return True
    return False

hmax = array[0][0]
hmin = 101
for i in range(n):
    for j in range(n):
        hmax = max(hmax, array[i][j])
        hmin = min(hmin, array[i][j])

ans = []
for h in range(hmin - 1, hmax + 1):
    result = 0
    chk = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if dfs(i, j, h, chk) == True:
                result += 1
    ans.append(result)

print(max(ans))
