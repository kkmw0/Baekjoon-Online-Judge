import heapq
import sys
input = sys.stdin.readline

INF = int(1e9)

n, m, x = map(int, input().split())
graph1 = [[] for _ in range(n + 1)]
graph2 = [[] for _ in range(n + 1)]
distance1 = [INF] * (n + 1)
distance2 = [INF] * (n + 1)

for _ in range(m):
    a, b, t = map(int, input().split())
    graph1[a].append((b, t))
    graph2[b].append((a, t))

def dijkstra(start, graph, distance):
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

dijkstra(x, graph1, distance1)
dijkstra(x, graph2, distance2)

max_value = 0
for i in range(1, n + 1):
    max_value = max(max_value, distance1[i] + distance2[i])

print(max_value)
