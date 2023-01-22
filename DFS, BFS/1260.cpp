#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, v;
bool visited[1001];
vector<int> graph[1001];

void dfs(int x){
    if(visited[x]) return;
    visited[x] = true;

    cout << x << ' ';
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        if(!visited[now]) dfs(now);
    }
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        cout << now << ' ';
        for(int i = 0; i < graph[now].size(); i++){
            int tmp = graph[now][i];
            if(!visited[tmp]){
                visited[tmp] = true;
                q.push(tmp);
            }
        }
    }
}

int main(void){
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());

    dfs(v);
    cout << '\n';
    fill_n(visited, 1001, false);
    bfs(v);
    return 0;
}