#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r, cnt = 1;
int visited[100001];
vector<int> graph[100001];

void dfs(int x){
    visited[x] = cnt++;
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        if(visited[now] == 0) dfs(now);
    }
}

int main(void){
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
    dfs(r);
    for(int i = 1; i <= n; i++){
        cout << visited[i] << '\n';
    }
    return 0;
}
