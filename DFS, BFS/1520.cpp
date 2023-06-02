#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[500][500];
long long d[500][500];

long long dfs(int x, int y){
    if(x == n - 1 && y == m - 1) return 1;
    if(d[x][y] != -1) return d[x][y];

    long long &result = d[x][y];
    result = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(graph[nx][ny] < graph[x][y]) result += dfs(nx, ny);
    }
    return result;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << dfs(0, 0) << '\n';
    return 0;
}