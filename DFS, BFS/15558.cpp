#include <iostream>
#include <queue>

using namespace std;

int n, k;
int graph[2][200001];
bool visited[2][200001];

bool bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    visited[0][0] = true;

    while(!q.empty()){
        int now = q.front().first.first;
        int line = q.front().first.second;
        int t = q.front().second;
        q.pop();

        if(now >= n) return true;

        if(graph[line][now + 1] == 1 && !visited[line][now + 1]){
            visited[line][now + 1] = true;
            q.push({{now + 1, line}, t + 1});
        }
        if(now - 1 > t && graph[line][now - 1] == 1 && !visited[line][now - 1]){
            visited[line][now - 1] = true;
            q.push({{now - 1, line}, t + 1});
        }

        if(line == 0){
            if(graph[1][now + k] == 1 && !visited[1][now + k]){
                visited[1][now + k] = true;
                q.push({{now + k, 1}, t + 1});
            }
        }
        else{
            if(graph[0][now + k] == 1 && !visited[0][now + k]){
                visited[0][now + k] = true;
                q.push({{now + k, 0}, t + 1});
            }
        }
    }
    return false;
}

int main(void){
    cin >> n >> k;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 200001; j++){
            graph[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++) scanf("%1d", &graph[0][i]);
    for(int i = 0; i < n; i++) scanf("%1d", &graph[1][i]);
    if(bfs()) cout << 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}