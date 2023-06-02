#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, m, r, result;
int item[101];
int d[101];
vector<pair<int, int>> graph[101];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});
    d[start] = 0;

    while(!pq.empty()){
        int now = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();

        if(d[now] < dist) continue;

        for(int i = 0; i < graph[now].size(); i++){
            int cost = d[now] + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push({graph[now][i].first, -cost});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) cin >> item[i];
    for(int i = 0; i < r; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill_n(d, 101, INF);
    for(int i = 1; i <= n; i++){
        dijkstra(i);
        
        int s = 0;
        for(int j = 1; j <= n; j++){
            if(d[j] <= m) s += item[j];
        }
        if(s > result) result = s;
        fill_n(d, 101, INF);
    }
    cout << result << '\n';
    return 0;
}