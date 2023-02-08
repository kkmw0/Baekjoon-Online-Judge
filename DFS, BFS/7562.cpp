#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int t, l, x1, x2, y1, y2;
int mv[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
bool visited[300][300];

void init(){
    for(int i = 0; i < 300; i++){
        fill_n(visited[i], 300, false);
    }
}

int bfs(int x, int y, int target_x, int target_y){
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    visited[x][y] = true;

    while(!q.empty()){
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int cost = q.front().second;
        q.pop();

        if(now_x == target_x && now_y == target_y) return cost;

        for(int i = 0; i < 8; i++){
            int nx = now_x + mv[i][0];
            int ny = now_y + mv[i][1];

            if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({{nx, ny}, cost + 1});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        init();
        cin >> l >> x1 >> y1 >> x2 >> y2;
        cout << bfs(x1, y1, x2, y2) << '\n';
    }
    return 0;
}