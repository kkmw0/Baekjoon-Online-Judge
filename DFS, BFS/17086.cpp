#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, result;
int mv[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
int graph[50][50];
bool visited[50][50];
queue<pair<int, int>> q;

void bfs(){ 
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = true;
        q.pop();

        for(int i = 0; i < 8; i++){
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                graph[nx][ny] = graph[x][y] + 1;
                result = max(result, graph[nx][ny]);
                q.push({nx, ny});
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
            if(graph[i][j] == 1){
                q.push({i, j});
                graph[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    bfs();
    cout << result << '\n';
    return 0;
}