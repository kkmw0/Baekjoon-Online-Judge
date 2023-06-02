#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int z, x, y;
};

int l, r, c;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dz[2] = {-1, 1};
char graph[31][31][31];
bool visited[31][31][31];
pos start, target;

void init(){
    for(int k = 0; k < l; k++){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                visited[k][i][j] = false;
            }
        }
    }
}

int bfs(int start_x, int start_y, int start_z){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{start_x, start_y}, {start_z, 0}});
    visited[start_z][start_x][start_y] = true;

    while(!q.empty()){
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int now_z = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if(target.x == now_x && target.y == now_y && target.z == now_z) return cost;

        for(int i = 0; i < 4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(graph[now_z][nx][ny] == '#' || visited[now_z][nx][ny]) continue;
            visited[now_z][nx][ny] = true;
            q.push({{nx, ny}, {now_z, cost + 1}});
        }
        for(int i = 0; i < 2; i++){
            int nz = now_z + dz[i];

            if(nz < 0 || nz >= l) continue;
            if(graph[nz][now_x][now_y] == '#' || visited[nz][now_x][now_y]) continue;
            visited[nz][now_x][now_y] = true;
            q.push({{now_x, now_y}, {nz, cost + 1}});
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        cin >> l >> r >> c;
        if(l == 0 || r == 0 || c == 0) break;

        init();
        for(int k = 0; k < l; k++){
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    cin >> graph[k][i][j];
                    if(graph[k][i][j] == 'S') start = {k, i, j};
                    if(graph[k][i][j] == 'E') target = {k, i, j};
                }
            }
        }
        int result = bfs(start.x, start.y, start.z);
        if(result == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << result << " minute(s).\n";
    }
    return 0;
}