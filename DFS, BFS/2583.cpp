#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, result, cnt = 1;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[101][101];
int graph[101][101];
vector<int> value;

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if(graph[nx][ny] == 0 && !visited[nx][ny]){
            cnt++;
            dfs(nx, ny);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2; j++){
            for(int k = x1; k < x2; k++){
                graph[j][k] = 1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cnt = 1;
            if(!graph[i][j] && !visited[i][j]){
                dfs(i, j);
                result++;
                value.push_back(cnt);
            }
        }
    }
    sort(value.begin(), value.end());

    cout << result << '\n';
    for(int i = 0; i < value.size(); i++) cout << value[i] << ' ';
    return 0;
}