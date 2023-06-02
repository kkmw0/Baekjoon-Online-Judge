#include <iostream>

using namespace std;

struct Shark{
    int speed, d, size;
};

int n, m, k, result;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
Shark board[100][100];

void catch_shark(int y){
    for(int x = 0; x < n; x++){
        if(board[x][y].size != 0){
            result += board[x][y].size;
            board[x][y].speed = 0;
            board[x][y].d = 0;
            board[x][y].size = 0;
            break;
        }
    }
}

void move_shark(){
    Shark new_board[100][100] = {0, };
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            new_board[x][y].speed = 0;
            new_board[x][y].d = 0;
            new_board[x][y].size = 0;
        }
    }

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(board[x][y].size != 0){
                int d = board[x][y].d;
                int speed = board[x][y].speed;
                if(d == 1 || d == 2){
                    int tmp = (n - 1) * 2;
                    if(speed >= tmp) speed %= tmp;

                    int nx = x;
                    for(int i = 0; i < speed; i++){
                        nx += dx[d];
                        if(nx < 0){
                            d = 2;
                            nx += 2;
                        }
                        if(nx >= n){
                            d = 1;
                            nx -= 2;
                        }
                    }
                    if(new_board[nx][y].size < board[x][y].size){
                        new_board[nx][y].speed = board[x][y].speed;
                        new_board[nx][y].d = d;
                        new_board[nx][y].size = board[x][y].size;
                    }
                }
                else{
                    int tmp = (m - 1) * 2;
                    if(speed >= tmp) speed %= tmp;

                    int ny = y;
                    for(int i = 0; i < speed; i++){
                        ny += dy[d];
                        if(ny < 0){
                            d = 3;
                            ny += 2;
                        }
                        if(ny >= m){
                            d = 4;
                            ny -= 2;
                        }
                    }
                    if(new_board[x][ny].size < board[x][y].size){
                        new_board[x][ny].speed = board[x][y].speed;
                        new_board[x][ny].d = d;
                        new_board[x][ny].size = board[x][y].size;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int x, y, s, d, b;
        cin >> x >> y >> s >> d >> b;
        x--, y--;
        board[x][y] = {s, d, b};
    }

    for(int y = 0; y < m; y++){
        catch_shark(y);
        move_shark();
    }
    cout << result << '\n';
    return 0;
}