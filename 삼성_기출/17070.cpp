#include <iostream>
#include <queue>

using namespace std;

struct Pipe{
    int x, y, type;
};

int n;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
int board[17][17];

int bfs(int x, int y){
    queue<Pipe> q;
    q.push({x, y, 0});

    int result = 0;
    while(!q.empty()){
        Pipe pipe = q.front();
        int now_x = pipe.x;
        int now_y = pipe.y;
        int type = pipe.type;
        q.pop();

        if(now_x == n && now_y == n){
            result++;
            continue;
        }

        if(type == 0){
            int nx = now_x + dx[0];
            int ny = now_y + dy[0];
            if(nx <= n && ny <= n && board[nx][ny] == 0){
                q.push({nx, ny, 0});
            }

            nx = now_x + dx[2];
            ny = now_y + dy[2];
            if(nx <= n && ny <= n && board[nx][ny] == 0){
                if(board[nx - 1][ny] == 0 && board[nx][ny - 1] == 0){
                    q.push({nx, ny, 2});
                }
            }
        }
        else if(type == 1){
            int nx = now_x + dx[1];
            int ny = now_y + dy[1];
            if(nx <= n && ny <= n && board[nx][ny] == 0){
                q.push({nx, ny, 1});
            }

            nx = now_x + dx[2];
            ny = now_y + dy[2];
            if(nx <= n && ny <= n && board[nx][ny] == 0){
                if(board[nx - 1][ny] == 0 && board[nx][ny - 1] == 0){
                    q.push({nx, ny, 2});
                }
            }
        }
        else{
            int nx = now_x + dx[2];
            int ny = now_y + dy[2];
            if(nx <= n && ny <= n && board[nx][ny] == 0){
                if(board[nx - 1][ny] == 0 && board[nx][ny - 1] == 0){
                    q.push({nx, ny, 2});
                }
            }

            for(int i = 0; i < 2; i++){
                nx = now_x + dx[i];
                ny = now_y + dy[i];

                if(nx <= n && ny <= n && board[nx][ny] == 0){
                    q.push({nx, ny, i});
                }
            }
        }
    }
    return result;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }
    if(board[n][n] == 1) cout << 0 << '\n';
    else{
        int result = bfs(1, 2);
        cout << result << '\n';
    }
    return 0;
}