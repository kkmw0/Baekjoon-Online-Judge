#include <iostream>
#include <vector>

using namespace std;

int n, a, b, m, result;
bool visited[101];
vector<int> graph[101];

void dfs(int start, int end, int cnt){
    visited[start] = true;
    if(start == end){
        result = cnt;
        return;
    }
    for(int i = 0; i < graph[start].size(); i++){
        int now = graph[start][i];
        if(!visited[now]) dfs(now, end, cnt + 1);
    }
}

int main(void){
    cin >> n >> a >> b >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(a, b, 0);
    if(result != 0) cout << result << '\n';
    else cout << -1 << '\n';
    return 0;
}