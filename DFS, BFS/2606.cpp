#include <iostream>
#include <vector>

using namespace std;

int n, m, result;
bool visited[101];
vector<int> graph[101];

void dfs(int x){
    if(visited[x]) return;
    visited[x] = true;
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        if(!visited[now]) {
            result++;
            dfs(now);
        }
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    cout << result << '\n';
    return 0;
}