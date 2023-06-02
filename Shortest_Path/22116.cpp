#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int board[1001][1001];
bool visited[1001][1001];
priority_queue<pair<int, pair<int, int>>> pq;

void dijkstra(){
    visited[0][0] = true;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        pq.pop();

        if(visited[now_x][now_y]) continue;

        visited[now_x][now_y] = true;
        result = max(result, cost);
        if(now_x == n - 1 && now_y == n - 1) break;

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
            pq.push({-abs(board[now_x][now_y] - board[nx][ny]), {nx, ny}});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    if(n == 1) cout << 0 << '\n';
    else{
        int a = abs(board[0][0] - board[0][1]);
        int b = abs(board[0][0] - board[1][0]);
        pq.push({-a, {0, 1}});
        pq.push({-b, {1, 0}});

        dijkstra();
        cout << result << '\n';
    }
    return 0;
}