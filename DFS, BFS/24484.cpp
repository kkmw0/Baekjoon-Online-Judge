#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m, r, value = 1;
long long result;
long long visited[100001];
long long check[100001];
vector<long long> graph[100001];

void dfs(int x, int cnt){
    visited[x] = cnt;
    check[x] = value++;
    for(int i = 0; i < graph[x].size(); i++){
        long long now = graph[x][i];
        if(now != r && visited[now] == 0) dfs(now, cnt + 1);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end(), greater<long long>());
    dfs(r, 0);
    for(int i = 1; i <= n; i++) result += check[i] * visited[i];
    cout << result << '\n';
    return 0;
}