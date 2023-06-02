#include <iostream>

using namespace std;

int n, m, pos_x, pos_y, d;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int graph[51][51];

int turn_left(int x){
    x--;
    if(x == -1) return 3;
    return x;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> pos_x >> pos_y >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    int result = 0;
    while(true){
        int turn_cnt = 0;
        if(graph[pos_x][pos_y] == 0){
            graph[pos_x][pos_y] = 9;
            result++;
        }

        int now_d = d;
        bool flag = false;
        for(int i = 0; i < 4; i++){
            now_d = turn_left(now_d);
            int nx = pos_x + dx[now_d];
            int ny = pos_y + dy[now_d];

            if(graph[nx][ny] == 0){
                flag = true;
                break;
            }
            turn_cnt++;
        }
        if(flag){
            pos_x += dx[now_d];
            pos_y += dy[now_d];
            d = now_d;
            continue;
        }
        else{
            int nx = pos_x - dx[d];
            int ny = pos_y - dy[d];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || graph[nx][ny] == 1) break;
            pos_x = nx;
            pos_y = ny;
            continue;
        }
    }
    cout << result << '\n';
    return 0;
}