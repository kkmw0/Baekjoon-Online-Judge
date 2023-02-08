#include <iostream>
#include <vector>

using namespace std;

int n;
long long result;
bool visited[500001];
vector<int> graph[500001];

void dfs(int x, long long d){
    if(x != 1 && !visited[x] && graph[x].size() == 1){
        result += d;
        return;
    }
    visited[x] = true;
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        if(!visited[now]) dfs(now, d + 1);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    if(result % 2) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}