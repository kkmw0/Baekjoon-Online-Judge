#include <iostream>
#include <queue>

using namespace std;

int visited[1001][1001];
int fire[1001][1001];
char graph[1001][1001];
int r, c, start_x, start_y, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

void move_fire(){
    while(!q2.empty()){
        int now_x = q2.front().first;
        int now_y = q2.front().second;
        q2.pop();

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(fire[nx][ny] >= 0 || graph[nx][ny] == '#') continue;
            fire[nx][ny] = fire[now_x][now_y] + 1;
            q2.push({nx, ny});
        }
    }
}

int bfs(){
    while(!q1.empty()){
        int now_x = q1.front().first;
        int now_y = q1.front().second;
        q1.pop();

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= r || ny >= c) return visited[now_x][now_y] + 1;

            if(visited[nx][ny] >= 0 || graph[nx][ny] == '#') continue;
            if(fire[nx][ny] != -1 && fire[nx][ny] <= visited[now_x][now_y] + 1) continue;
            visited[nx][ny] = visited[now_x][now_y] + 1;
            q1.push({nx, ny});
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            visited[i][j] = fire[i][j] = -1;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'J'){
                visited[i][j] = 0;
                q1.push({i, j});
            }
            if(graph[i][j] == 'F'){
                fire[i][j] = 0;
                q2.push({i, j});
            }
        }
    }

    move_fire();
    int result = bfs();
    if(result == -1) cout << "IMPOSSIBLE\n";
    else cout << result << '\n';
    return 0;
}