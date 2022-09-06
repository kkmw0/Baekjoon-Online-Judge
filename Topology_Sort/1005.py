from collections import deque
import sys
import copy

input = sys.stdin.readline

def topology_sort(w):
    result = copy.deepcopy(time)
    q = deque()

    for i in range(1, n + 1):
        if indegree[i] == 0:
            q.append(i)

    while q:
        now = q.popleft()

        for i in graph[now]:
            result[i] = max(result[i], result[now] + time[i])
            indegree[i] -= 1

            if indegree[i] == 0:
                q.append(i)

    ans.append(result[w])
    
t = int(input())
ans = []

for _ in range(t):
    n, m = map(int, input().split())
    indegree = [0] * (n + 1)
    graph = [[] for _ in range(n + 1)]
    time = [0] + list(map(int, input().split()))

    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        indegree[b] += 1

    w = int(input())
    topology_sort(w)

for i in ans:
    print(i)
