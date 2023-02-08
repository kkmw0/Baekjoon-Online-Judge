#include <iostream>

using namespace std;

int r, c, wolf, sheep, total_wolf, total_sheep;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char graph[250][250];
bool visited[250][250];

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if(graph[nx][ny] != '#' && !visited[nx][ny]){
            if(graph[nx][ny] == 'k') sheep++;
            else if(graph[nx][ny] == 'v') wolf++;
            dfs(nx, ny);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(graph[i][j] != '#' && !visited[i][j]){
                if(graph[i][j] == 'k') sheep++;
                else if(graph[i][j] == 'v') wolf++;

                dfs(i, j);
                if(sheep > wolf) total_sheep += sheep;
                else total_wolf += wolf;
                wolf = sheep = 0;
            }
        }
    }
    cout << total_sheep << ' ' << total_wolf << '\n';
    return 0;
}