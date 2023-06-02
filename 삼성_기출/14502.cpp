#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[9][9];
int tmp[9][9];
bool visited[9][9];
vector<pair<int, int>> v, pick;

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tmp[i][j] = graph[i][j];
            visited[i][j] = false;
        }
    }
}

void dfs_virus(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(tmp[nx][ny] == 1 || tmp[nx][ny] == 2) continue;
        if(!visited[nx][ny]){
            tmp[nx][ny] = 2;
            dfs_virus(nx, ny);
        }
    }
}

void move_virus(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tmp[i][j] == 2 && !visited[i][j]){
                dfs_virus(i, j);
            }
        }
    }
}

void dfs(int d){
    if(pick.size() == 3){
        init();
        for(int i = 0; i < pick.size(); i++){
            int x = pick[i].first;
            int y = pick[i].second;
            tmp[x][y] = 1;
        }
        move_virus();
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(tmp[i][j] == 0) cnt++;
            }
        }
        result = max(result, cnt);
        return;
    }
    for(int i = d; i < v.size(); i++){
        pick.push_back({v[i].first, v[i].second});
        dfs(i + 1);
        pick.pop_back();
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 0) v.push_back({i, j});
        }
    }
    dfs(0);
    cout << result << '\n';
    return 0;
}