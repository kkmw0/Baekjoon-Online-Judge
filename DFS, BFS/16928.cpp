#include <iostream>
#include <queue>

using namespace std;

int n, m;
int ladder[101], snake[101];

void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int s, e;
        cin >> s >> e;
        ladder[s] = e;
    }
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        ladder[s] = e;
    }
}

int bfs(int start){
    bool visited[101] = {false, };
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(now == 100) return cost;

        for(int i = 1; i <= 6 && now + i <= 100; i++){
            int nx = now + i;
            if(visited[nx]) continue;
            if(ladder[nx] != 0){
                int tmp = ladder[nx];
                visited[tmp] = true;
                q.push({tmp, cost + 1});
            }
            else if(snake[nx] != 0){
                int tmp = snake[nx];
                visited[tmp] = true;
                q.push({tmp, cost + 1});
            }
            else{
                visited[nx] = true;
                q.push({nx, cost + 1});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    cout << bfs(1) << '\n';
    return 0;
}