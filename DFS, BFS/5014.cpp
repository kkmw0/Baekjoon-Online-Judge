#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d, result;
bool visited[1000001];

int bfs(int start, int end){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(now == end) return cost;

        if(u != 0 && now + u <= f && !visited[now + u]){
            visited[now + u] = true;
            q.push({now + u, cost + 1});
        }
        if(d != 0 && now - d >= 1 && !visited[now - d]){
            visited[now - d] = true;
            q.push({now - d, cost + 1});
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> f >> s >> g >> u >> d;
    int result = bfs(s, g);
    if(result == -1) cout << "use the stairs" << '\n';
    else cout << result << '\n';
    return 0;
}