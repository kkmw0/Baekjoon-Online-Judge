#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int t, n, m, k;
long long d[101], result[101];
vector<pair<int, int>> graph[101];

void init(){
    for(int i = 1; i <= n; i++){
        result[i] = 0;
        graph[i].clear();
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
            int cost = dist + graph[now][i].second;
            int idx = graph[now][i].first;
            if(d[idx] > cost){
                d[idx] = cost;
                pq.push({-cost, idx});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        cin >> n >> m;

        init();
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }

        cin >> k;
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            for(int i = 1; i <= n; i++) d[i] = INF;

            dijkstra(x);
            for(int i = 1; i <= n; i++) result[i] += d[i];
        }

        int answer = 1e9, value = 1e9;
        for(int i = 1; i <= n; i++){
            if(result[i] >= INF) continue;
            if(result[i] < value){
                value = result[i];
                answer = i;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}