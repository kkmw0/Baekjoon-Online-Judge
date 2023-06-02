#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int x, y, z, cost;
};

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[1000][1000];
bool visited[1000][1000][2]; // 0 : 벽 안뚫고 왔을 때, 1 : 벽 뚫고 왔을 때

int bfs(int x, int y, int z){
    queue<Node> q;
    q.push({x, y, z, 1});
    visited[x][y][z] = true;

    while(!q.empty()){
        Node node = q.front();
        q.pop();

        if(node.x == n - 1 && node.y == m - 1) return node.cost;

        for(int i = 0; i < 4; i++){
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == 1){
                if(node.z == 0){
                    visited[nx][ny][1] = true;
                    q.push({nx, ny, 1, node.cost + 1});
                }
            }
            else{
                if(!visited[nx][ny][node.z]){
                    visited[nx][ny][node.z] = true;
                    q.push({nx, ny, node.z, node.cost + 1});
                }
            }

        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        for(int j = 0; j < m; j++){
            board[i][j] = str[j] - '0';
        }
    }
    cout << bfs(0, 0, 0) << '\n';
    return 0;
}