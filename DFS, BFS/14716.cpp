#include <iostream>
#include <cmath>

using namespace std;

int n, m, result;
int mv[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
int graph[250][250];
bool visited[250][250];

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 8; i++){
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if(graph[nx][ny] && !visited[nx][ny]) dfs(nx, ny);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] && !visited[i][j]) {
                dfs(i, j);
                result++;
            }
        }
    }
    cout << result << '\n';
    return 0;
}