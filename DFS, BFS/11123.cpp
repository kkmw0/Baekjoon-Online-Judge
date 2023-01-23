#include <iostream>
#include <algorithm>

using namespace std;

int t, h, w, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char graph[101][101];
bool visited[101][101];

void init(){
    result = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            visited[i][j] = false;
        }
    }
}

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if(graph[nx][ny] == '#' && !visited[nx][ny]){
            dfs(nx, ny);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        init();

        cin >> h >> w;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> graph[i][j];
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(graph[i][j] == '#' && !visited[i][j]){
                    dfs(i, j);
                    result++;
                }
            }
        }
        cout << result << '\n';
    }
    return 0;
}