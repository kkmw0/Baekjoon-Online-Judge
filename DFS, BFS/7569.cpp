#include <iostream>
#include <queue>

using namespace std;

int m, n, h, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dz[2] = {-1, 1};
int graph[101][101][101];
bool visited[101][101][101];
queue<pair<pair<int, int>, pair<int, int>>> q;

void bfs(){
    while(!q.empty()){
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int now_z = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        result = cost;
        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(graph[now_z][nx][ny] == 0 && !visited[now_z][nx][ny]){
                visited[now_z][nx][ny] = true;
                graph[now_z][nx][ny] = 1;
                q.push({{nx, ny}, {now_z, cost + 1}});
            }
        }
        for(int i = 0; i < 2; i++){
            int nz = now_z + dz[i];

            if(nz < 0 || nz >= h) continue;
            if(graph[nz][now_x][now_y] == 0 && !visited[nz][now_x][now_y]){
                visited[nz][now_x][now_y] = true;
                graph[nz][now_x][now_y] = 1;
                q.push({{now_x, now_y}, {nz, cost + 1}});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> h;
    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> graph[k][i][j];
                if(graph[k][i][j] == 1) {
                    visited[k][i][j] = true;
                    q.push({{i, j}, {k, 0}});
                }
            }
        }
    }
    bfs();

    bool flag = false;
    for(int k = 0; k < h && !flag; k++){
        for(int i = 0; i < n && !flag; i++){
            for(int j = 0; j < m; j++){
                if(graph[k][i][j] == 0){
                    flag = true;
                    break;
                }
            }
        }
    }
    if(flag) cout << -1 << '\n';
    else cout << result << '\n';
    return 0;
}