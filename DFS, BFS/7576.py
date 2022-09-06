import sys
from collections import deque
input = sys.stdin.readline

m, n = map(int, input().split())

array = []
for _ in range(n):
    array.append(list(map(int, input().split())))

# 상, 하, 좌, 우 정의
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

time = 0
q = deque()
for i in range(n):
    for j in range(m):
        if array[i][j] == 1:
            q.append((i, j))

while q:
    x, y = q.popleft()

    # 상, 하, 좌, 우 검사
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx <= -1 or nx >= n or ny <= -1 or ny >= m:
            continue

        if array[nx][ny] == 0:
            array[nx][ny] = array[x][y] + 1
            q.append((nx, ny))
            time = array[nx][ny]

flag = 0
for i in range(n):
    for j in range(m):
        if array[i][j] == 0:
            flag = 1
            break

if flag:
    print(-1)
if time - 1 == -1 and not flag:
    print(0)
elif time - 1 != -1 and not flag:
    print(time - 1)
