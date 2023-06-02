#include <iostream>
#include <queue>

using namespace std;

int n, m, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[301][301];
int tmp[301][301];
bool visited[301][301];
bool flag;

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tmp[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void check_dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(graph[nx][ny] > 0 && !visited[nx][ny]) check_dfs(nx, ny);
    }    
}

bool check(){
    init();

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] > 0 && !visited[i][j]){
                check_dfs(i, j);
                cnt++;
            }
        }
    }
    if(cnt == 0) return false;
    else if(cnt >= 2){
        flag = true;
        return false;
    }
    else{
        result++;
        return true;
    }
}

void melt(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tmp[i][j] > 0){
                int now = graph[i][j] - tmp[i][j];
                if(now < 0) graph[i][j] = 0;
                else graph[i][j] = now;
            }
        }
    }
}

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(visited[nx][ny]) continue;
        if(graph[nx][ny] == 0){
            dfs(nx, ny);
        }
        else if(graph[nx][ny] >= 1) tmp[nx][ny]++;
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
    while(check()){
        init();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(graph[i][j] == 0 && !visited[i][j]) dfs(i, j);
            }
        }
        melt();
    }
    if(!flag) cout << 0 << '\n';
    else cout << result << '\n';
    return 0;
}