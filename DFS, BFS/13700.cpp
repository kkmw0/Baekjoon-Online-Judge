#include <iostream>
#include <queue>

using namespace std;

int n, s, d, f, b, k;
int visited[100001];

int bfs(int start, int end){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(now == end) return cost;

        if(now + f <= n && visited[now + f] == 0){
            visited[now + f] = 1;
            q.push({now + f, cost + 1});
        }
        if(now - b >= 1 && visited[now - b] == 0){
            visited[now - b] = 1;
            q.push({now - b, cost + 1});
        }
    }
    return -1;
}

int main(void){
    cin >> n >> s >> d >> f >> b >> k;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        visited[x] = -1;
    }
    int result = bfs(s, d);
    if(result == -1) cout << "BUG FOUND" << '\n';
    else cout << result << '\n';
    return 0;
}