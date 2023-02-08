#include <iostream>
#include <algorithm>

using namespace std;

int r, c, result = 1e9;
int graph[5][5];
int tmp[5][5];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int apple, int move){
    if(apple == 3){
        result = move < result ? move : result;
    }
    else{
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if(tmp[nx][ny] == -1) continue;
            else if(tmp[nx][ny] == 1){
                tmp[x][y] = -1;
                dfs(nx, ny, apple + 1, move + 1);
            }
            else{
                tmp[x][y] = -1;
                dfs(nx, ny, apple, move + 1);
            }
        }
        tmp[x][y] = graph[x][y];
    }
}

int main(void){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> graph[i][j];
            tmp[i][j] = graph[i][j];
        }
    }
    cin >> r >> c;
    dfs(r, c, 0, 0);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << tmp[i][j];
        }
        cout << '\n';
    }
    if(result >= 1e9) cout << -1 << '\n';
    else cout << result << '\n';
    return 0;
}