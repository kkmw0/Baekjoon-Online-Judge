#include <iostream>
#include <queue>

using namespace std;

bool flag;
int n, m, result;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int board[100][70];
bool visited[100][70];

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        int now_h = board[now_x][now_y];
        q.pop();

        for(int i = 0; i < 8; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] > now_h) flag = false;
            if(visited[nx][ny] || board[nx][ny] != now_h) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                flag = true;
                bfs(i, j);
                if(flag) result++;
            }
        }
    }
    cout << result << '\n';
    return 0;
}