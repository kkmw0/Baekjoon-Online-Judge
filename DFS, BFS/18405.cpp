#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k, s, x, y;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[201][201];
queue<pair<int, int>> q[1001];

void spread(){
    int new_board[201][201];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            new_board[i][j] = board[i][j];
        }
    }

    for(int i = 1; i <= k; i++){
        vector<pair<int, int>> pos;
        while(!q[i].empty()){
            int now_x = q[i].front().first;
            int now_y = q[i].front().second;
            q[i].pop();

            for(int j = 0; j < 4; j++){
                int nx = now_x + dx[j];
                int ny = now_y + dy[j];

                if(nx < 1 || ny < 1 || nx > n || ny > n || new_board[nx][ny] != 0) continue;
                new_board[nx][ny] = new_board[now_x][now_y];
                pos.push_back({nx, ny});
            }
        }
        for(int j = 0; j < pos.size(); j++) q[i].push({pos[j].first, pos[j].second});
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            board[i][j] = new_board[i][j];
        }
    }  
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
            if(board[i][j] != 0) q[board[i][j]].push({i, j});
        }
    }
    cin >> s >> x >> y;

    for(int i = 0; i < s; i++) spread();
    cout << board[x][y] << '\n';
    return 0;
}