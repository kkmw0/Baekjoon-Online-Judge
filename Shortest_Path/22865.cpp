#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, a, b, c, m;
int arr[3], d[3][100001];
vector<pair<int, int>> graph[100001];

void init(){
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= n; j++){
            d[i][j] = INF;
        }
    }
}

void dijkstra(int start, int num){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[num][start] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[num][now] < dist) continue;

        for(int i = 0; i < graph[now].size(); i++){
            int idx = graph[now][i].first;
            int cost = dist + graph[now][i].second;
            if(d[num][idx] > cost){
                d[num][idx] = cost;
                pq.push({-cost, idx});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < 3; i++) cin >> arr[i];
    cin >> m;
    for(int i = 0; i < m; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        graph[x].push_back({y, cost});
        graph[y].push_back({x, cost});
    }

    init();
    for(int i = 0; i < 3; i++) dijkstra(arr[i], i);

    int result = 0, dist = -1;
    for(int i = 1; i <= n; i++){
        if(i == arr[0] || i == arr[1] || i == arr[2]) continue;
        int min_value = min({d[0][i], d[1][i], d[2][i]});
        if(min_value > dist){
            dist = min_value;
            result = i;
        }
    }
    cout << result << '\n';
    return 0;
}