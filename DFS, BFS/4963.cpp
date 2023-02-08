#include <iostream>

using namespace std;

int h, w, result;
int mv[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
bool visited[50][50];
int graph[50][50];

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
    for(int i = 0; i < 8; i++){
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if(graph[nx][ny] == 1 && !visited[nx][ny]) dfs(nx, ny);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    while(true){
        init();
        cin >> w >> h;
        if(h == 0 && w == 0) break;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> graph[i][j];
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(graph[i][j] == 1 && !visited[i][j]){
                    dfs(i, j);
                    result++;
                }
            }
        }
        cout << result << '\n';
    }
    return 0;
}