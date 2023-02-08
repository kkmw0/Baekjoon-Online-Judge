#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, m, q;
int visited[1001];
vector<int> graph[1001];

void bfs(int start){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int d = q.front().second;
        q.pop();

        if(d > visited[x]) continue;

        for(int i = 0; i < graph[x].size(); i++){
            int now = graph[x][i];
            if(visited[now] > d + 1){
                visited[now] = d + 1;
                q.push({now, d + 1});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);

        fill_n(visited, 1001, INF);
        bfs(1);
        for(int j = 1; j <= n; j++){
            if(visited[j] >= INF) cout << -1 << ' ';
            else cout << visited[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}