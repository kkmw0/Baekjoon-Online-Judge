#include <iostream>
#include <queue>

using namespace std;

int n, m;
int graph[300][300];
bool visited[300][300];

int bfs(int x, int y){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{x, y}, {graph[x][y], 0}});
    visited[x][y] = true;

    while(!q.empty()){
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int booster = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if(now_x == n - 1 && now_y == m - 1) return cost;

        for(int i = now_x + 1; i <= now_x + booster; i++){
            if(i < n && !visited[i][now_y]){
                visited[i][now_y] = true;
                q.push({{i, now_y}, {graph[i][now_y], cost + 1}});
            }
        }
        for(int i = now_y + 1; i <= now_y + booster; i++){
            if(i < m && !visited[now_x][i]){
                visited[now_x][i] = true;
                q.push({{now_x, i}, {graph[now_x][i], cost + 1}});
            }
        } 
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
    cout << bfs(0, 0) << '\n';
    return 0;
}