#include <iostream>
#include <queue>

using namespace std;

int r, c;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visited_1[51][51];
int visited_2[51][51];
char graph[51][51];

queue<pair<int, int>> water;
queue<pair<int, int>> q;

void init(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            visited_1[i][j] = visited_2[i][j] = -1;
        }
    }
}

void move_water(){
    while(!water.empty()){
        int now_x = water.front().first;
        int now_y = water.front().second;
        water.pop();

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(visited_2[nx][ny] >= 0 || graph[nx][ny] == 'X' || graph[nx][ny] == 'D') continue;
            visited_2[nx][ny] = visited_2[now_x][now_y] + 1;
            water.push({nx, ny});
        }
    }
}

int bfs(){
    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(graph[nx][ny] == 'D') return visited_1[now_x][now_y] + 1;

            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(visited_1[nx][ny] >= 0 || graph[nx][ny] == 'X') continue;
            if(visited_2[nx][ny] != -1 && visited_2[nx][ny] <= visited_1[now_x][now_y] + 1) continue;
            visited_1[nx][ny] = visited_1[now_x][now_y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;

    init();
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'S'){
                visited_1[i][j] = 0;
                q.push({i, j});
            }
            else if(graph[i][j] == '*'){
                visited_2[i][j] = 0;
                water.push({i, j});
            }
        }
    }
    move_water();
    int result = bfs();
    if(result == -1) cout << "KAKTUS\n";
    else cout << result << '\n';
    return 0;
}