#include <iostream>
#include <queue>

using namespace std;

int m, n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[101][101];
bool visited[101][101];

int dijkstra(int x, int y){
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {x, y}});
    visited[x][y] = true;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        pq.pop();

        if(now_x == n && now_y == m) return cost;

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                if(graph[nx][ny] == 1) pq.push({-(cost + 1), {nx, ny}});
                else pq.push({-cost, {nx, ny}});
            }
        }
    }
} 

int main(void){
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    cout << dijkstra(1, 1) << '\n';
    return 0;
}