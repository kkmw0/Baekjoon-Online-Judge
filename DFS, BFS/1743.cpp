#include <iostream>

using namespace std;

int n, m, k, result, cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[101][101];
bool visited[101][101];

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(x < 1 || y < 1 || x > n || y > m) continue;
        if(graph[nx][ny] == 1 && !visited[nx][ny]){
            cnt++;
            dfs(nx, ny);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cnt = 1;
            if(graph[i][j] == 1 && !visited[i][j]) dfs(i, j);
            if(cnt > result) result = cnt;
        }
    }
    cout << result << '\n';
    return 0;
}