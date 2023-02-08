#include <iostream>
#include <queue>

using namespace std;

int n, r1, c1, r2, c2;
int mv[6][2] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};
bool visited[200][200];

int bfs(int x1, int y1, int x2, int y2){
    queue<pair<pair<int, int>, int>> q;
    q.push({{x1, y1}, 0});
    visited[x1][y1] = true;

    while(!q.empty()){
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int cost = q.front().second;
        q.pop();

        if(now_x == x2 && now_y == y2) return cost;

        for(int i = 0; i < 6; i++){
            int nx = now_x + mv[i][0];
            int ny = now_y + mv[i][1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({{nx, ny}, cost + 1});
            }
        }
    }
    return -1;
}

int main(void){
    cin >> n >> r1 >> c1 >> r2 >> c2;
    cout << bfs(r1, c1, r2, c2) << '\n';
    return 0;
}