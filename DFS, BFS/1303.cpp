#include <iostream>
#include <cmath>

using namespace std;

int n, m, cnt, total_W, total_B;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char graph[100][100];
bool visited[100][100];

void dfs(int x, int y, char ch){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if(graph[nx][ny] == ch && !visited[nx][ny]){
            cnt++;
            dfs(nx, ny, ch);
        }
    }
}

void init(){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cnt = 0;
            if(graph[i][j] == 'B' && !visited[i][j]) {
                cnt = 1;
                dfs(i, j, 'B');
            }
            total_B += pow(cnt, 2);
        }
    }
    init();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cnt = 0;
            if(graph[i][j] == 'W' && !visited[i][j]){
                cnt = 1;
                dfs(i, j, 'W');
            }
            total_W += pow(cnt, 2);
        }
    }
    cout << total_W << ' ' << total_B << '\n';
    return 0;
}