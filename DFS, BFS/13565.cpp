#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, flag;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[1001][1001];
bool visited[1001][1001];

bool bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == m - 1) return true;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(graph[nx][ny] == 0 && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        if(graph[0][i] == 0){
            if(bfs(0, i)){
                flag = 1;
                break;
            }            
        }
    }
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}