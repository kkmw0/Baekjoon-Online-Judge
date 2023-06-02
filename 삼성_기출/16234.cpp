#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, l, r, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int arr[51][51];

void bfs(int x, int y, int idx, int status[][51], int& cnt, int& s){
    bool visited[51][51] = {false, };
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        cnt++;
        status[now_x][now_y] = idx;
        s += arr[now_x][now_y];

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            int d = abs(arr[nx][ny] - arr[now_x][now_y]);
            if(visited[nx][ny] == 0 && d >= l && d <= r){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    bool flag = true;
    while(flag){
        flag = false;

        int status[51][51] = {0, };
        int cnt[2501] = {0, };
        int s[2501] = {0, };
        int idx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(status[i][j] == 0){
                    idx++;
                    bfs(i, j, idx, status, cnt[idx], s[idx]);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int now = status[i][j];
                int avg = s[now] / cnt[now];

                if(arr[i][j] != avg){
                    arr[i][j] = avg;
                    flag = true;
                }
            }
        }
        if(flag) result++;
    }
    cout << result << '\n';
    return 0;
}