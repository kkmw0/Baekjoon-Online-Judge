#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos{
    int x, y, t;
};

int n, m, result = 1e9;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[50][50];
vector<pair<int, int>> pos, pick;

int bfs(){
    int tmp[50][50];
    int empty_cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tmp[i][j] = board[i][j];
            if(tmp[i][j] == 2) tmp[i][j] = 0;
            if(tmp[i][j] == 0) empty_cnt++;
        }
    }

    bool visited[51][51] = {false, };
    queue<Pos> q;
    for(int i = 0; i < m; i++){
        empty_cnt--;
        tmp[pick[i].first][pick[i].second] = 2;
        q.push({pick[i].first, pick[i].second, 0});
        visited[pick[i].first][pick[i].second] = true;
    }

    while(!q.empty()){
        Pos now = q.front();
        q.pop();

        if(tmp[now.x][now.y] == 0) empty_cnt--;
        if(empty_cnt == 0) return now.t;

        for(int i = 0; i < 4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(!visited[nx][ny] && tmp[nx][ny] != 1){
                visited[nx][ny] = true;
                q.push({nx, ny, now.t + 1});
            }
        }
    }
    return 1e9;
}

void dfs(int cnt){
    if(pick.size() == m){
        int value = bfs();
        result = min(result, value);
        return;
    }
    for(int i = cnt; i < pos.size(); i++){
        pick.push_back({pos[i].first, pos[i].second});
        dfs(i + 1);
        pick.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                pos.push_back({i, j});
            }
        }
    }

    dfs(0);
    if(result == 1e9) cout << -1 << '\n';
    else cout << result << '\n';
    return 0;
}