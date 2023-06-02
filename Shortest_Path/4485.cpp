#include <iostream>
#include <queue>

using namespace std;

int n, test_case = 1;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int graph[125][125];

int dijkstra(int x, int y){
    bool visited[125][125] = {false, };
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-graph[x][y], {x, y}});
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
            visited[nx][ny] = true;
            pq.push({-(cost + graph[nx][ny]), {nx, ny}});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> graph[i][j];
            }
        }
        cout << "Problem " << test_case++ << ": " << dijkstra(0, 0) << '\n';
    }
    return 0;
}