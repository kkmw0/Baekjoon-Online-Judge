#include <iostream>
#include <queue>

using namespace std;

int n, k;
bool visited[100001];

int bfs(int start, int end){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(now == end) return cost;

        if(now + 1 <= 100000 && !visited[now + 1]){
            visited[now + 1] = true;
            q.push({now + 1, cost + 1});
        }
        if(now - 1 >= 0 && !visited[now - 1]){
            visited[now - 1] = true;
            q.push({now - 1, cost + 1});
        }
        if(now << 1 <= 100000 && !visited[now << 1]){
            visited[now << 1] = true;
            q.push({now << 1, cost + 1});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    cout << bfs(n, k) << '\n';
    return 0;
}