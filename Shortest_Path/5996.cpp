#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int t, c, s, e;
int d[2501];
vector<pair<int, int>> graph[2501];

void init(){
    for(int i = 1; i <= t; i++){
        d[i] = INF;
    }
}

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
            int idx = graph[now][i].first;
            int cost = d[now] + graph[now][i].second;
            if(cost < d[idx]){
                d[idx] = cost;
                pq.push({-cost, idx});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t >> c >> s >> e;
    init();
    for(int i = 0; i < c; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    dijkstra(s);
    cout << d[e] << '\n';
    return 0;
}