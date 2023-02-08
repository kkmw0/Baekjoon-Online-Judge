#include <iostream>

using namespace std;

int r, c, k, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[5][5];
char graph[5][5];

void dfs(int x, int y, int cnt){
    visited[x][y] = true;
    if(cnt == k && x == 0 && y == c - 1){
        result++;
        visited[x][y] = false;
        return;
    }
    if(cnt >= k && x != 0 && y != c - 1){
        visited[x][y] = false;
        return;       
    }
    else{
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(graph[nx][ny] == 'T') continue;
            if(!visited[nx][ny]) dfs(nx, ny, cnt + 1);
        }
        visited[x][y] = false;
    }
}

int main(void){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> graph[i][j];
        }
    }
    dfs(r - 1, 0, 1);
    cout << result << '\n';
    return 0;
}