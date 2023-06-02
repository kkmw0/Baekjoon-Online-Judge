#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int arr[50][50];
bool visited[50][50];

int dijkstra(int x, int y){
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {x, y}});
    visited[x][y] = true;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        pq.pop();

        if(now_x == n - 1 && now_y == n - 1) return cost;

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
            if(arr[nx][ny] == 0) pq.push({-(cost + 1), {nx, ny}});
            else pq.push({-cost, {nx, ny}});
            visited[nx][ny] = true;
        }
    }
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    cout << dijkstra(0, 0) << '\n';
    return 0;
}