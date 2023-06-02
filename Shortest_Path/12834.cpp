#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;

int n, v, e, a, b, result;
int arr[2], pos[1001], d[2][1001];
vector<pair<int, int>> graph[1001];

void init(){
    arr[0] = a, arr[1] = b;
    for(int i = 0; i <= v; i++){
        d[0][i] = INF;
        d[1][i] = INF;
    }
}

void dijkstra(int start, int idx){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[idx][start] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[idx][now] < dist) continue;

        for(int i = 0; i < graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            int node = graph[now][i].first;
            if(d[idx][node] > cost){
                d[idx][node] = cost;
                pq.push({-cost, node});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> v >> e >> a >> b;
    for(int i = 0; i < n; i++) cin >> pos[i];
    for(int i = 0; i < e; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }

    init();
    for(int i = 0; i < 2; i++) dijkstra(arr[i], i);
    for(int i = 0; i < n; i++){
        int now = pos[i];
        int dist_a = d[0][now] >= INF ? -1 : d[0][now];
        int dist_b = d[1][now] >= INF ? -1 : d[1][now];
        result += (dist_a + dist_b);
    }
    cout << result << '\n';
    return 0;
}