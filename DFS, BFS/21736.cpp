#include <iostream>

using namespace std;

int n, m, result;
pair<int, int> pos;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char graph[600][600];
bool visited[600][600];

void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(graph[nx][ny] == 'X' || visited[nx][ny]) continue;
        else if(graph[nx][ny] == 'P' && !visited[nx][ny]) result++;
        visited[nx][ny] = true;
        dfs(nx, ny);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'I'){
                pos.first = i;
                pos.second = j;
            }
        }
    }
    visited[pos.first][pos.second] = true;
    dfs(pos.first, pos.second);
    if(result == 0) cout << "TT" << '\n';
    else cout << result << '\n';
    return 0;
}