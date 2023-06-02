#include <iostream>

using namespace std;

int n, m, k, result, cnt;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dice_value[7] = {0, 1, 2, 3, 4, 5, 6};
int board[21][21];
bool visited[21][21];

void init(){
    cnt = 0;
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            visited[i][j] = false;
        }
    }
}

void move_dice(int d){
    int tmp;
    switch(d)
    {
        case 0:
            tmp = dice_value[1];
            dice_value[1] = dice_value[5];
            dice_value[6] = 7 - dice_value[1];
            dice_value[2] = tmp;
            dice_value[5] = 7 - dice_value[2];
            break;

        case 1:
            tmp = dice_value[1];
            dice_value[1] = dice_value[4];
            dice_value[6] = 7 - dice_value[1];
            dice_value[3] = tmp;
            dice_value[4] = 7 - dice_value[3];
            break;

        case 2:
            tmp = dice_value[1];
            dice_value[1] = dice_value[2];
            dice_value[6] = 7 - dice_value[1];
            dice_value[5] = tmp;
            dice_value[2] = 7 - dice_value[5];
            break;

        case 3:
            tmp = dice_value[1];
            dice_value[1] = dice_value[3];
            dice_value[6] = 7 - dice_value[1];
            dice_value[4] = tmp;
            dice_value[3] = 7 - dice_value[4];
            break;
    }
}

void get_same(int x, int y, int value){
    cnt++;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if(board[nx][ny] == value && !visited[nx][ny]){
            get_same(nx, ny, value);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }

    int d = 1, x = 1, y = 1;
    for(int i = 0; i < k; i++){
        init();
        int nx = x + dx[d];
        int ny = y + dy[d];

        if(nx < 1 || ny < 1 || nx > n || ny > m){
            d = (d + 2) % 4;
            nx = x + dx[d];
            ny = y + dy[d];
        }

        move_dice(d);
        get_same(nx, ny, board[nx][ny]);
        result += cnt * board[nx][ny];

        if(dice_value[6] > board[nx][ny]) d = (d + 1) % 4;
        else if(dice_value[6] < board[nx][ny]) d = (d + 3) % 4;
        x = nx;
        y = ny;
    }
    cout << result << '\n';
    return 0;
}