#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
int visited[100001];
vector<int> graph[100001];

void dfs(int x, int cnt){
    visited[x] = cnt;
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        if(now != r && visited[now] == 0) dfs(now, cnt + 1);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end(), greater<int>());

    dfs(r, 0);
    for(int i = 1; i <= n; i++){
        if(i != r && visited[i] == 0) cout << -1 << '\n';
        else cout << visited[i] << '\n';
    }
    return 0;
}