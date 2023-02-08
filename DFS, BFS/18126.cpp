#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, result;
bool visited[5001];
vector<pair<long long, long long>> graph[5001];

void dfs(long long x, long long value){
    visited[x] = true;
    for(int i = 0; i < graph[x].size(); i++){
        long long now = graph[x][i].first;
        long long cost = graph[x][i].second;
        if(!visited[now]){
            visited[now] = true;
            result = max(result, value + cost);
            dfs(now, value + cost);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    dfs(1, 0);
    cout << result << '\n';
    return 0;
}