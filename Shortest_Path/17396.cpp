#include <iostream>
#include <vector>
#include <queue>
#define INF 1e13

using namespace std;

int n, m;
long long d[300001];
bool is_visible[300001];
vector<pair<int, long long>> graph[300001];

void init(){
    for(int i = 0; i < n; i++){
        d[i] = INF;
    }
}

void dijkstra(int start){
    priority_queue<pair<long long, int>> pq;
    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()){
        long long dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist) continue;

        for(int i = 0; i < graph[now].size(); i++){
            int idx = graph[now][i].first;
            long long cost = d[now] + graph[now][i].second;
            if(cost < d[idx] && (idx == n - 1 || !is_visible[idx])){
                d[graph[now][i].first] = cost;
                pq.push({-cost, idx});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> is_visible[i];
    for(int i = 0; i < m; i++){
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }

    init();
    dijkstra(0);
    if(d[n - 1] >= INF) cout << -1 << '\n';
    else cout << d[n - 1] << '\n';
    return 0;
}