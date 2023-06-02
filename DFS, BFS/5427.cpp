#include <iostream>
#include <queue>

using namespace std;

int t, h, w;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dist1[1001][1001];
int dist2[1001][1001];
char graph[1001][1001];
queue<pair<int, int>> fire;
queue<pair<int, int>> sang;

void init(){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            dist1[i][j] = dist2[i][j] = -1;
        }
    }
    while(!fire.empty()) fire.pop();
    while(!sang.empty()) sang.pop();
}

void move_fire(){
    while(!fire.empty()){
        int now_x = fire.front().first;
        int now_y = fire.front().second;
        fire.pop();

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(graph[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
            dist2[nx][ny] = dist2[now_x][now_y] + 1;
            fire.push({nx, ny});
        }
    }
}

int bfs(){
    while(!sang.empty()){
        int now_x = sang.front().first;
        int now_y = sang.front().second;
        sang.pop();

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) return dist1[now_x][now_y] + 1;

            if(dist1[nx][ny] >= 0 || graph[nx][ny] == '#') continue;
            if(dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[now_x][now_y] + 1) continue;
            dist1[nx][ny] = dist1[now_x][now_y] + 1;
            sang.push({nx, ny});
        }        
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        cin >> w >> h;

        init();
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> graph[i][j];
                if(graph[i][j] == '@'){
                    dist1[i][j] = 0;
                    sang.push({i, j});
                }
                if(graph[i][j] == '*'){
                    dist2[i][j] = 0;
                    fire.push({i, j});
                }
            }
        }
        move_fire();
        int result = bfs();
        if(result == -1) cout << "IMPOSSIBLE\n";
        else cout << result << '\n';
    }
    return 0;
}