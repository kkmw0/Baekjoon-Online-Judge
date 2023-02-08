#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, r, cnt = 1;
int visited[100001];
vector<int> graph[100001];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = cnt;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i = 0; i < graph[x].size(); i++){
            int now = graph[x][i];
            if(visited[now] == 0 && now != start){
                cnt++;
                visited[now] = cnt;
                q.push(now);
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
    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end(), greater<int>());
    bfs(r);
    for(int i = 1; i <= n; i++) cout << visited[i] << '\n';
    return 0;
}