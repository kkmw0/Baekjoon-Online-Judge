#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, m, result, c1, c2, r1, r2;
vector<pair<int, int>> graph[801];
int d[801];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist) continue;

        for(int i = 0; i < graph[now].size(); i++){
            int cost = d[now] + graph[now][i].second;

            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> c1 >> c2;

    fill_n(d, 801, INF);
    dijkstra(1);
    r1 = d[c1];
    r2 = d[c2];

    fill_n(d, 801, INF);
    dijkstra(c1);
    if(r1 < INF) r1 += d[c2];
    if(r2 < INF){
        r2 += d[c2];
        r2 += d[n];
    }

    fill_n(d, 801, INF);
    dijkstra(c2);
    if(r1 < INF) r1 += d[n];
    if(r1 >= INF && r2 >= INF) result = -1;
    else result = min(r1, r2);

    if(result >= INF) result = -1;
    cout << result << '\n';
    return 0;
}