#include <iostream>
#include <queue>
#define INF 1e9

using namespace std;

int n;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int graph[2222][2222];
int d[2222][2222];

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = INF;
        }
    }    
}

void dijkstra(int x, int y){
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {x, y}});
    d[x][y] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        pq.pop();

        for(int i = 0; i < 2; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            int nd = cost;

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(graph[now_x][now_y] <= graph[nx][ny]) nd += (graph[nx][ny] - graph[now_x][now_y] + 1);
            if(nd >= d[nx][ny]) continue;

            d[nx][ny] = nd;
            pq.push({-nd, {nx, ny}});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    init();
    dijkstra(0, 0);
    cout << d[n - 1][n - 1] << '\n';
    return 0;
}