#include <iostream>

using namespace std;

struct Pos{
    int x1, y1, x2, y2;
};

int r, c, t;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[2][50][50];
Pos pos;

void spread_dust(int cur){
    int next = (cur + 1) % 2;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[cur][i][j] == -1) board[next][i][j] = -1;
            else board[next][i][j] = 0;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int value = board[cur][i][j] / 5;
            int s = 0;
            for(int d = 0; d < 4; d++){
                int nx = i + dx[d];
                int ny = j + dy[d];

                if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                if(board[next][nx][ny] != -1){
                    board[next][nx][ny] += value;
                    s += value;                    
                }
            }
            if(board[next][i][j] != -1) board[next][i][j] += board[cur][i][j] - s;
        }
    }
}

void move_dust(int cur){
    for(int i = pos.x1 - 1; i > 0; i--){
        board[cur][i][0] = board[cur][i - 1][0];
    }
    for(int i = 0; i < c - 1; i++){
        board[cur][0][i] = board[cur][0][i + 1];
    }
    for(int i = 0; i < pos.x1; i++){
        board[cur][i][c - 1] = board[cur][i + 1][c - 1];
    }
    for(int i = c - 1; i > 1; i--){
        board[cur][pos.x1][i] = board[cur][pos.x1][i - 1];
    }
    board[cur][pos.x1][1] = 0;

    for(int i = pos.x2 + 1; i < r; i++){
        board[cur][i][0] = board[cur][i + 1][0];
    }
    for(int i = 0; i < c - 1; i++){
        board[cur][r - 1][i] = board[cur][r - 1][i + 1];
    }
    for(int i = r - 1; i > pos.x2; i--){
        board[cur][i][c - 1] = board[cur][i - 1][c - 1];
    }
    for(int i = c - 1; i > 1; i--){
        board[cur][pos.x2][i] = board[cur][pos.x2][i - 1];
    }
    board[cur][pos.x2][1] = 0;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> t;

    pos = {-1, 0, 0, 0};
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[0][i][j];
            if(board[0][i][j] == -1){
                if(pos.x1 == -1){
                    pos.x1 = i;
                    pos.y1 = j;
                }
                else{
                    pos.x2 = i;
                    pos.y2 = j;
                }
            }
        }
    }

    int cur = 0;
    for(int i = 0; i < t; i++){
        spread_dust(cur);
        cur = (cur + 1) % 2;
        move_dust(cur);
    }

    int result = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[cur][i][j] != -1) result += board[cur][i][j];
        }
    }
    cout << result << '\n';
    return 0;
}