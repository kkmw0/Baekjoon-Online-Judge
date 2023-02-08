#include <iostream>
#include <queue>

using namespace std;

int n, m, x, y;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visited[1000][1000];
int graph[1000][1000];

void bfs(int _x, int _y){
    queue<pair<int, int>> q;
    q.push({_x, _y});
    visited[_x][_y] = 0;

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(graph[nx][ny] == 0 || graph[nx][ny] == 2) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = visited[now_x][now_y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 2){
                x = i;
                y = j;
            }
        }
    }
    bfs(x, y);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0 && graph[i][j] == 1) cout << -1 << ' ';
            else cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}