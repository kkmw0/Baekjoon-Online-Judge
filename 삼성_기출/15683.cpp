#include <iostream>

using namespace std;

struct CCTV{
    int type, x, y;
};

int n, m, cctv_cnt, result = 1e9;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cctv_rotate[6] = {0, 4, 2, 4, 4, 1};
int board[8][8];
int tmp[8][8];
CCTV cctv[8];

void update(CCTV c, int d){
    d %= 4;
    if(d == 0){
        for(int x = c.x - 1; x >= 0; x--){
            if(board[x][c.y] == 6) break;
            board[x][c.y] = -1;
        }
    }
    else if(d == 1){
        for(int y = c.y + 1; y < m; y++){
            if(board[c.x][y] == 6) break;
            board[c.x][y] = -1;
        }
    }
    else if(d == 2){
        for(int x = c.x + 1; x < n; x++){
            if(board[x][c.y] == 6) break;
            board[x][c.y] = -1;
        }
    }
    else if(d == 3){
        for(int y = c.y - 1; y >= 0; y--){
            if(board[c.x][y] == 6) break;
            board[c.x][y] = -1;
        }
    }
}

void dfs(int idx){
    if(idx == cctv_cnt){
        int s = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0) s++;
            }
        }
        if(s < result) result = s;
        return;
    }

    int tmp[8][8];
    int type = cctv[idx].type;
    for(int d = 0; d < cctv_rotate[type]; d++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                tmp[i][j] = board[i][j];
            }
        }

        switch (type){
            case 1:
                update(cctv[idx], d);
                break;
            case 2:
                update(cctv[idx], d);
                update(cctv[idx], d + 2);
                break;
            case 3:
                update(cctv[idx], d);
                update(cctv[idx], d + 1);
                break;
            case 4:
                update(cctv[idx], d);
                update(cctv[idx], d + 1);
                update(cctv[idx], d + 2);
                break;
            case 5:
                update(cctv[idx], d);
                update(cctv[idx], d + 1);
                update(cctv[idx], d + 2);
                update(cctv[idx], d + 3);
                break;
        }
        dfs(idx + 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = tmp[i][j];
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6){
                cctv[cctv_cnt].type = board[i][j];
                cctv[cctv_cnt].x = i;
                cctv[cctv_cnt].y = j;
                cctv_cnt++;
            }
        }
    }
    dfs(0);
    cout << result << '\n';
    return 0;
}