#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long n, m, r, result, cnt = 1;
long long depth[100001];
long long visited[100001];
vector<long long> graph[100001];

void bfs(long long start){
    queue<pair<long long, long long>> q;
    q.push({start, 0});
    depth[start] = 0;
    visited[start] = cnt;

    while(!q.empty()){
        long long x = q.front().first;
        long long cost = q.front().second;
        q.pop();

        for(int i = 0; i < graph[x].size(); i++){
            long long now = graph[x][i];
            if(depth[now] == 0 && now != start){
                cnt++;
                visited[now] = cnt;
                depth[now] = cost + 1;
                q.push({now, cost + 1});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        long long a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
    fill_n(visited, 100001, -1);

    bfs(r);
    for(int i = 1; i <= n; i++) result += visited[i] * depth[i];
    cout << result << '\n';
    return 0;
}