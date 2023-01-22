#include <iostream>
#include <algorithm>

using namespace std;

bool flag;
int r, c, mv;
int graph[5][5];
int value[5][5];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int move){
    if(move == 3){
        if(value[x][y] >= 2) flag = 1;
    }
    else{
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if(graph[nx][ny] == -1) continue;
            else if(graph[nx][ny] == 1) value[nx][ny] = max(value[nx][ny], value[x][y] + 1);
            else value[nx][ny] = max(value[nx][ny], value[x][y]);

            graph[x][y] = -1;
            dfs(nx, ny, move + 1);
        }
    }
}

int main(void){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> graph[i][j];
        }
    }
    cin >> r >> c;
    dfs(r, c, mv);
    flag ? cout << 1 << '\n' : cout << 0 << '\n';
}