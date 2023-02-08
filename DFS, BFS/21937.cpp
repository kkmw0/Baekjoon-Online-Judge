#include <iostream>
#include <vector>

using namespace std;

int n, m, x, result;
bool visited[100001];
vector<int> graph[100001];

void dfs(int start){
    visited[start] = true;
    for(int i = 0; i < graph[start].size(); i++){
        int now = graph[start][i];
        if(!visited[now]){
            result++;
            dfs(now);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }
    cin >> x;
    dfs(x);
    cout << result << '\n';
    return 0;
}