#include <iostream>
#include <queue>

using namespace std;

int m, n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[1000][1000];
bool visited[1000][1000];

int dijkstra(int x, int y){
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-board[x][y], {x, y}});
    visited[x][y] = true;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        pq.pop();

        if(now_x == m - 1 && now_y == n - 1) return cost;

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(board[nx][ny] == -1 || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            pq.push({-(cost + board[nx][ny]), {nx, ny}});
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    if(board[0][0] == -1) cout << -1 << '\n';
    else cout << dijkstra(0, 0) << '\n';
    return 0;
}