#include <iostream>
#include <queue>

using namespace std;

int n;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
bool visited[64][64];
int graph[64][64];

void bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int now = graph[x][y];
        if(x == n - 1 && y == n - 1){
            cout << "HaruHaru" << '\n';
            return;
        }
        for(int i = 0; i < 2; i++){
            int nx = x + dx[i] * now;
            int ny = y + dy[i] * now;

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    cout << "Hing" << '\n';
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    bfs();
    return 0;
}