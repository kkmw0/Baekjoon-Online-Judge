#include <iostream>

using namespace std;

int n, m, x, y, k;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dice_value[7];
int dice_idx[7];
int cmd[1000];
int board[20][20];

void init(){
    for(int i = 1; i <= 6; i++) dice_idx[i] = i;
}

void move_dice(int d){
    int tmp;
    int arr[7];
    for(int i = 1; i <= 6; i++) arr[i] = dice_value[i];

    switch(d)
    {
        case 0:
            tmp = dice_idx[1];
            dice_idx[1] = dice_idx[4];
            dice_idx[6] = 7 - dice_idx[1];
            dice_idx[3] = tmp;
            dice_idx[4] = 7 - dice_idx[3];

            dice_value[1] = arr[4];
            dice_value[6] = arr[3];
            dice_value[3] = arr[1];
            dice_value[4] = arr[6];
            break;

        case 1:
            tmp = dice_idx[1];
            dice_idx[1] = dice_idx[3];
            dice_idx[6] = 7 - dice_idx[1];
            dice_idx[4] = tmp;
            dice_idx[3] = 7 - dice_idx[4];

            dice_value[1] = arr[3];
            dice_value[6] = arr[4];
            dice_value[3] = arr[6];
            dice_value[4] = arr[1];
            break;

        case 2:
            tmp = dice_idx[1];
            dice_idx[1] = dice_idx[5];
            dice_idx[6] = 7 - dice_idx[1];
            dice_idx[2] = tmp;
            dice_idx[5] = 7 - dice_idx[2];

            dice_value[1] = arr[5];
            dice_value[6] = arr[2];
            dice_value[2] = arr[1];
            dice_value[5] = arr[6];
            break;

        case 3:
            tmp = dice_idx[1];
            dice_idx[1] = dice_idx[2];
            dice_idx[6] = 7 - dice_idx[1];
            dice_idx[5] = tmp;
            dice_idx[2] = 7 - dice_idx[5];

            dice_value[1] = arr[2];
            dice_value[6] = arr[5];
            dice_value[2] = arr[6];
            dice_value[5] = arr[1];
            break;
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        cmd[i] = x - 1;
    }
    
    init();
    for(int i = 0; i < k; i++){
        int nx = x + dx[cmd[i]];
        int ny = y + dy[cmd[i]];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

        move_dice(cmd[i]);
        if(board[nx][ny] == 0) board[nx][ny] = dice_value[6];
        else{
            dice_value[6] = board[nx][ny];
            board[nx][ny] = 0;
        }

        cout << dice_value[1] << '\n';
        x = nx;
        y = ny;
    }
    return 0;
}