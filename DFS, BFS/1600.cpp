#include <iostream>
#include <queue>

using namespace std;

struct Monkey{
    int x, y, h, cost;
};

int k, w, h;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int mv[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-1, -2}};
int board[200][200];
bool visited[31][200][200];

int bfs(int x, int y){
    queue<Monkey> q;
    q.push({x, y, k, 0});
    visited[k][x][y] = true;

    while(!q.empty()){
        int now_x = q.front().x;
        int now_y = q.front().y;
        int now_h = q.front().h;
        int cost = q.front().cost;
        q.pop();

        if(now_x == h - 1 && now_y == w - 1) return cost;

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(board[nx][ny] != 1 && !visited[now_h][nx][ny]){
                visited[now_h][nx][ny] = true;
                q.push({nx, ny, now_h, cost + 1});
            }
        }
        
        if(now_h == 0) continue;

        for(int i = 0; i < 8; i++){
            int nx = now_x + mv[i][0];
            int ny = now_y + mv[i][1];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(board[nx][ny] != 1 && !visited[now_h - 1][nx][ny]){
                visited[now_h - 1][nx][ny] = true;
                q.push({nx, ny, now_h - 1, cost + 1});
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k >> w >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> board[i][j];
        }
    }
    cout << bfs(0, 0) << '\n';
    return 0;
}