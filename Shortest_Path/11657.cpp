#include <iostream>
#include <vector>
#define INF 1e10

using namespace std;

int n, m;
long long dist[501];
vector<pair<int, pair<int, int>>> graph;

bool bellmanFord(int start){
    dist[start] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            int cost = graph[j].first;
            int a = graph[j].second.first;
            int b = graph[j].second.second;

            if(dist[a] == INF) continue;
            if(dist[b] > dist[a] + cost){
                dist[b] = dist[a] + cost;
                if(i == n) return true;
            }
        }
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) dist[i] = INF;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }

    if(bellmanFord(1)) cout << -1 << '\n';
    else{
        for(int i = 2; i <= n; i++){
            if(dist[i] >= INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
    return 0;
}