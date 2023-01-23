#include <iostream>
#include <algorithm>

using namespace std;

bool visited[51][51];
int graph[51][51];
int t, n, m, k, cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(graph[nx][ny] == 0) continue;
        if(!visited[nx][ny]) dfs(nx, ny);
    }
}

void init(){
    cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            graph[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        init();
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            graph[y][x] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && graph[i][j] == 1){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}