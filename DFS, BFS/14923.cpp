#include <iostream>
#include <queue>

using namespace std;

struct MAZE{
    int x, y, cost, flag;
};

int n, m, h_x, h_y, e_x, e_y;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[1001][1001];
bool visited[2][1001][1001];

int bfs(int x, int y){
    queue<MAZE> q;
    q.push({x, y, 1, 0});
    visited[0][x][y] = true;

    while(!q.empty()){
        int now_x = q.front().x;
        int now_y = q.front().y;
        int cost = q.front().cost;
        int flag = q.front().flag;
        q.pop();

        if(now_x == e_x && now_y == e_y) return cost;

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 1 || ny < 1 || nx > n || ny > m || visited[flag][nx][ny]) continue;
            if(board[nx][ny] == 0){
                visited[flag][nx][ny] = true;
                q.push({nx, ny, cost + 1, flag});
            }
            if(board[nx][ny] == 1 && !flag){
                visited[!flag][nx][ny] = true;
                q.push({nx, ny, cost, !flag});
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> h_x >> h_y >> e_x >> e_y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }
    cout << bfs(h_x, h_y) << '\n';
    return 0;
}