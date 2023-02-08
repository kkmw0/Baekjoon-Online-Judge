#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, result;
bool visited[21];
vector<pair<int, int>> graph;

void dfs(int x, int cnt){
    if(x >= m - 1){
        result = max(result, cnt);
        return;
    }
    else{
        int a = graph[x].first;
        int b = graph[x].second;
        if(!visited[a] && !visited[b]){
            visited[a] = visited[b] = true;
            dfs(x + 1, cnt + 2);
            visited[a] = visited[b] = false;
        }
        dfs(x + 1, cnt);
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph.push_back({a, b});
    }
    dfs(0, 0);
    if(result != n) result++;
    cout << result << '\n';
    return 0;
}