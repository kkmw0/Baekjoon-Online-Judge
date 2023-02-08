#include <iostream>
#include <queue>

using namespace std;

int n, m, a, b, pos_x, pos_y;
int mv[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
int path[501][501];
bool visited[501][501];
queue<pair<int, int>> q;

void bfs(int x, int y){
    q.push({x, y});
    visited[x][y] = true;
    path[x][y] = 0;

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int nx = now_x + mv[i][0];
            int ny = now_y + mv[i][1];

            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                path[nx][ny] = path[now_x][now_y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> pos_x >> pos_y;
    bfs(pos_x, pos_y);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cout << path[a][b] << ' ';
    }
    return 0;
}