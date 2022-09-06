import heapq
import sys
input = sys.stdin.readline

INF = int(1e9 + 1)
t = int(input())

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        for i in graph[now]:
            cost = dist + i[1]

            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    

for _ in range(t):
    n, d, c = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    distance = [INF] * (n + 1)

    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append((a, s))

    dijkstra(c)

    count = 0
    time = 0
    for i in distance:
        if i != INF:
            count += 1
            time = max(time, i)

    print(count, time)
