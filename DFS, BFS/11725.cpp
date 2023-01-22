#include <iostream>
#include <vector>

using namespace std;

int n;
int parent[100001];
vector<int> graph[100001];

void dfs(int x){
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        if(parent[now] == 0) parent[now] = x;
        else continue;
        dfs(now);
    }
}

int main(void){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) dfs(i);
    for(int i = 2; i <= n; i++){
        cout << parent[i] << '\n';
    }
    return 0;
}