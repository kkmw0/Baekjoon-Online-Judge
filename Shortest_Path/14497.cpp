#include <iostream>
#include <queue>

using namespace std;

int n, m, s_x, s_y, e_x, e_y;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char board[301][301];
bool visited[301][301];

int dijkstra(int x, int y){
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {x, y}});
    board[x][y] = '0';
    visited[x][y] = true;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        pq.pop();

        if(now_x == e_x && now_y == e_y) return cost;

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 1 || ny < 1 || nx > n || ny > m || visited[nx][ny]) continue;
            if(board[nx][ny] == '0'){
                visited[nx][ny] = true;
                pq.push({-cost, {nx, ny}});
            }
            else{
                board[nx][ny] = '0';
                visited[nx][ny] = true;
                pq.push({-(cost + 1), {nx, ny}});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s_x >> s_y >> e_x >> e_y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }
    cout << dijkstra(s_x, s_y) << '\n';
    return 0;
}