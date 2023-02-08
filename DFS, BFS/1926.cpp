#include <iostream>

using namespace std;

int n, m, total, result, cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[500][500];
bool visited[500][500];

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(graph[nx][ny] == 1 && !visited[nx][ny]){
            cnt++;
            dfs(nx, ny);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cnt = 1;
            if(graph[i][j] == 1 && !visited[i][j]){
                dfs(i, j);
                total++;
            }
            if(cnt > result) result = cnt;
        }
    }
    cout << total << '\n';
    if(total == 0) cout << 0 << '\n';
    else cout << result << '\n';
    return 0;
}