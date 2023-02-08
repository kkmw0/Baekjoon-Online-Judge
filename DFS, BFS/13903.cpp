#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c, n;
int graph[1000][1000];
bool visited[1000][1000];
vector<pair<int, int>> mv;
queue<pair<pair<int, int>, int>> q;

int bfs(){
    for(int i = 0; i < q.size(); i++){
        int x = q.front().first.first;
        int y = q.front().first.second;
        visited[x][y] = true;
    }

    while(!q.empty()){
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int cost = q.front().second;
        q.pop();

        if(now_x == r - 1) return cost;

        for(int i = 0; i < n; i++){
            int nx = now_x + mv[i].first;
            int ny = now_y + mv[i].second;

            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(graph[nx][ny] == 0) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({{nx, ny}, cost + 1});
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> graph[i][j];
            if(i == 0 && graph[i][j] == 1) q.push({{i, j}, 0});
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        mv.push_back({a, b});
    }
    cout << bfs() << '\n';
    return 0;
}