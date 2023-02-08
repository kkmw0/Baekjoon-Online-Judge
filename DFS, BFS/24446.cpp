#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, r;
int visited[100001];
vector<int> graph[100001];

void bfs(int start){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int cost = q.front().second;
        q.pop();

        for(int i = 0; i < graph[x].size(); i++){
            int now = graph[x][i];
            if(visited[now] == 0 && now != start){
                visited[now] = cost + 1;
                q.push({now, cost + 1});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(r);
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0 && i != r) cout << -1 << '\n';
        else cout << visited[i] << '\n';
    }

    return 0;
}