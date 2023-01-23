#include <iostream>
#include <vector>

using namespace std;

int n, m, result;
bool visited[1001];
vector<int> graph[1001];

void dfs(int x){
    visited[x] = true;
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        if(!visited[now]) dfs(now);
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            result++;
        }
    }
    cout << result << '\n';
    return 0;
}