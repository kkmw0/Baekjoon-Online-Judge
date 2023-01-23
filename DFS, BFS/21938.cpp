#include <iostream>

using namespace std;

int n, m, t, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[1001][1001];
bool visited[1001][1001];

void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(x < 0 || y < 0 || x >= n || y >= m) continue;
        if(graph[nx][ny] >= t && !visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int r, g, b, sum;
            cin >> r >> g >> b;
            sum = (r + g + b) / 3;
            graph[i][j] = sum;
        }
    }
    cin >> t;

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] >= t && !visited[i][j]){
                dfs(i, j);
                result++;
            }
        }
    }
    cout << result << '\n';
    return 0;
}