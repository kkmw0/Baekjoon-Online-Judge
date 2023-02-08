#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, e;
bool visited[300001];
vector<int> teleport[300001];

int bfs(int start, int end){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(now == end) return cost;

        if(now - 1 >= 1 && !visited[now - 1]){
            visited[now - 1] = true;
            q.push({now - 1, cost + 1});
        }
        if(now + 1 <= n && !visited[now + 1]){
            visited[now + 1] = true;
            q.push({now + 1, cost + 1});
        }

        for(int i = 0; i < teleport[now].size(); i++){
            int x = teleport[now][i];
            if(!visited[x]){
                visited[x] = true;
                q.push({x, cost + 1});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s >> e;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        teleport[a].push_back(b);
        teleport[b].push_back(a);
    }
    cout << bfs(s, e) << '\n';
    return 0;
}