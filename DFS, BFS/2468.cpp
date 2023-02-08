#include <iostream>

using namespace std;

int n, cnt, result, max_h = -1, min_h = 101;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[100][100];
bool visited[100][100];

void init(){
    cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
}

void dfs(int x, int y, int h){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(graph[nx][ny] > h && !visited[nx][ny]) dfs(nx, ny, h);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
            if(graph[i][j] > max_h) max_h = graph[i][j];
            if(graph[i][j] < min_h) min_h = graph[i][j];
        }
    }
    for(int h = max_h + 1; h >= min_h - 1; h--){
        init();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(graph[i][j] > h && !visited[i][j]){
                    dfs(i, j, h);
                    cnt++;
                }
            }
        }
        if(cnt > result) result = cnt;
    }
    cout << result << '\n';
    return 0;
}