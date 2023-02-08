#include <iostream>
#include <queue>

using namespace std;

int n, m, _x, _y, flag, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[3000][3000];
bool visited[3000][3000];

int bfs(int x, int y){
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    visited[x][y] = true;

    while(!q.empty()){
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int cost = q.front().second;
        q.pop();

        if(graph[now_x][now_y] == 3 || graph[now_x][now_y] == 4 || graph[now_x][now_y] == 5) {
            flag = 1;
            return cost;
        }

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(graph[nx][ny] == 1 || graph[nx][ny] == 2) continue;
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
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            graph[i][j] = str[j] - '0';
            if(graph[i][j] == 2){
                _x = i;
                _y = j;
            }
        }
    }
    result = bfs(_x, _y);
    if(flag) cout << "TAK" << '\n' << result << '\n';
    else cout << "NIE" << '\n';
    
    return 0;
}