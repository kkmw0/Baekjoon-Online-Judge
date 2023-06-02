#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int dx[4] = {1, 0, 1};
int dy[4] = {0, 1, 1};
int graph[1001][1001];
int result[1001][1001];
bool visited[1001][1001];

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    result[x][y] = graph[x][y];

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for(int i = 0; i < 3; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(!visited[nx][ny]){
                result[nx][ny] = result[now_x][now_y] + graph[nx][ny];
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
            if(result[nx][ny] < result[now_x][now_y] + graph[nx][ny]){
                result[nx][ny] = result[now_x][now_y] + graph[nx][ny];
                q.push({nx, ny});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> graph[i][j];
        }
    }
    bfs(1, 1);
    cout << result[n][m] << '\n';
    return 0;
}