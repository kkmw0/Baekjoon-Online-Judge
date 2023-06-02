#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int n, m, s, e;
int d[1001], path[1001];
vector<pair<int, int>> graph[1001];
vector<int> v;

void init(){
    for(int i = 1; i <= n; i++){
        d[i] = INF;
    }
}

void output(){
    cout << d[e] << '\n';

    int idx = e;
    while(idx != s){
        v.push_back(idx);
        idx = path[idx];
    }
    v.push_back(idx);

    int len = v.size();
    cout << len << '\n';
    for(int i = len - 1; i >= 0; i--){
        cout << v[i] << ' ';
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
            int cost = dist + graph[now][i].second;
            if(d[idx] > cost){
                d[idx] = cost;
                path[idx] = now;
                pq.push({-cost, idx});
            }
        }
    }
    output();
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    init();
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    cin >> s >> e;
    dijkstra(s);
    return 0;
}