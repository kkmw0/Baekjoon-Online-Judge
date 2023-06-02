#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dist[50][50];
char board[50][50];

void bfs(int x, int y){
    bool visited[50][50] = {false, };
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    dist[x][y] = 0;

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 'W') continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                dist[nx][ny] = dist[now_x][now_y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> board[i][j];
        }
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'L') bfs(i, j);

            for(int x = 0; x < n; x++){
                for(int y = 0; y < m; y++){
                    result = max(result, dist[x][y]);
                }
            }
        }
    }
    cout << result << '\n';
    return 0;
}