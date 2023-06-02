#include <iostream>

using namespace std;

int n, m, h, result = 4;
int board[31][11];

bool check(){
    bool flag = true;
    for(int i = 1; i <= n; i++){
        int pos = i;
        for(int j = 0; j <= h; j++){
            if(board[j][pos] == 1) pos++;
            else if(board[j][pos - 1] == 1) pos--;
        }
        if(pos != i) return flag = false;
    }
    return flag;
}

void dfs(int cnt, int x, int y){
    if(cnt >= result) return;
    if(check()){
        result = cnt;
        return;
    }

    if(cnt == 3) return;

    for(int i = x; i <= h; i++){
        for(int j = y; j < n; j++){
            if(board[i][j] == 0 && board[i][j - 1] == 0 && board[i][j + 1] == 0){
                board[i][j] = 1;
                dfs(cnt + 1, i, j);
                board[i][j] = 0;
            }
        }
        y = 1;
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }
    dfs(0, 1, 1);
    if(result == 4) cout << -1 << '\n';
    else cout << result << '\n';
    return 0;
}