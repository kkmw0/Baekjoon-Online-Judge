#include <iostream>

using namespace std;

int n, result = -1;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int pick[5];
int board[20][20], tmp[20][20];
bool visited[20][20];

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
}

void move_up(){
    for(int x = 1; x < n; x++){
        for(int y = 0; y < n; y++){
            for(int i = x; i >= 1; i--){
                if(tmp[i][y] == 0) break;
                if(tmp[i - 1][y] == 0){
                    tmp[i - 1][y] = tmp[i][y];
                    tmp[i][y] = 0;
                }
                else{
                    if(tmp[i - 1][y] == tmp[i][y] && !visited[i - 1][y]){
                        tmp[i - 1][y] *= 2;
                        tmp[i][y] = 0;
                        visited[i - 1][y] = true;
                    }
                    break;
                }
            }
        }
    }
}

void move_down(){
    for(int x = n - 2; x >= 0; x--){
        for(int y = 0; y < n; y++){
            for(int i = x; i <= n - 2; i++){
                if(tmp[i][y] == 0) break;
                if(tmp[i + 1][y] == 0){
                    tmp[i + 1][y] = tmp[i][y];
                    tmp[i][y] = 0;
                }
                else{
                    if(tmp[i + 1][y] == tmp[i][y] && !visited[i + 1][y]){
                        tmp[i + 1][y] *= 2;
                        tmp[i][y] = 0;
                        visited[i + 1][y] = true;
                    }
                    break;
                }
            }
        }
    }
}

void move_left(){
    for(int y = 1; y < n; y++){
        for(int x = 0; x < n; x++){
            for(int i = y; i >= 1; i--){
                if(tmp[x][i] == 0) break;
                if(tmp[x][i - 1] == 0){
                    tmp[x][i - 1] = tmp[x][i];
                    tmp[x][i] = 0;
                }
                else{
                    if(tmp[x][i - 1] == tmp[x][i] && !visited[x][i - 1]){
                        tmp[x][i - 1] *= 2;
                        tmp[x][i] = 0;
                        visited[x][i - 1] = true;
                    }
                    break;
                }
            }
        }
    }
}

void move_right(){
    for(int y = n - 2; y >= 0; y--){
        for(int x = 0; x < n; x++){
            for(int i = y; i <= n - 2; i++){
                if(tmp[x][i] == 0) break;
                if(tmp[x][i + 1] == 0){
                    tmp[x][i + 1] = tmp[x][i];
                    tmp[x][i] = 0;
                }
                else{
                    if(tmp[x][i + 1] == tmp[x][i] && !visited[x][i + 1]){
                        tmp[x][i + 1] *= 2;
                        tmp[x][i] = 0;
                        visited[x][i + 1] = true;
                    }
                    break;
                }
            }
        }
    }
}

void move_board(){
    for(int i = 0; i < 5; i++){
        init();
        if(pick[i] == 0) move_up();
        else if(pick[i] == 1) move_down();
        else if(pick[i] == 2) move_left();
        else move_right();
    }
}

void dfs(int cnt){
    if(cnt == 5){
        move_board();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(tmp[i][j] > result) result = tmp[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                tmp[i][j] = board[i][j];
            }
        }   
        return;
    }
    for(int i = 0; i < 4; i++){
        pick[cnt] = i;
        dfs(cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << result << '\n';
    return 0;
}