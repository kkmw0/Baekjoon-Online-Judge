#include <iostream>
#include <queue>

using namespace std;

struct STATUS{
    int x, y, sword, cost;
};

int n, m, t;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[101][101];
bool visited[2][101][101];

int bfs(int x, int y){
    queue<STATUS> q;
    q.push({x, y, 0, 0});
    visited[0][x][y] = true;

    while(!q.empty()){
        int now_x = q.front().x;
        int now_y = q.front().y;
        int sword = q.front().sword;
        int cost = q.front().cost;
        q.pop();

        if(cost > t) continue;
        if(now_x == n && now_y == m) return cost;

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 1 || ny < 1 || nx > n || ny > m || visited[sword][nx][ny]) continue;
            if(sword == 0){
                if(board[nx][ny] == 1) continue;
                else if(board[nx][ny] == 2){
                    visited[sword][nx][ny] = true;
                    q.push({nx, ny, 1, cost + 1});
                }
                else{
                    visited[sword][nx][ny] = true;
                    q.push({nx, ny, 0, cost + 1});      
                }
            }
            else if(sword == 1){
                visited[sword][nx][ny] = true;
                q.push({nx, ny, sword, cost + 1});
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }
    int result = bfs(1, 1);
    if(result == -1) cout << "Fail\n";
    else cout << result << '\n';
    return 0;
}