#include <iostream>
#include <queue>

using namespace std;

int r, c;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visited[5][5];
int graph[5][5];

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 0;

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        if(graph[now_x][now_y] == 1) return visited[now_x][now_y];

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if(graph[nx][ny] == -1) continue;
            else{
                if(!visited[nx][ny]){
                    visited[nx][ny] = visited[now_x][now_y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

int main(void){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> graph[i][j];
        }
    }
    cin >> r >> c;
    cout << bfs(r, c) << '\n';
    return 0;
}