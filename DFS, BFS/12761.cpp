#include <iostream>
#include <queue>

using namespace std;

int a, b, n, m;
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

        if(now - 1 >= 0 && !visited[now - 1]){
            visited[now - 1] = true;
            q.push({now - 1, cost + 1});
        }
        if(now + 1 <= 100000 && !visited[now + 1]){
            visited[now + 1] = true;
            q.push({now + 1, cost + 1});
        }
        if(now - a >= 0 && !visited[now - a]){
            visited[now - a] = true;
            q.push({now - a, cost + 1});
        }
        if(now + a <= 100000 && !visited[now + a]){
            visited[now + a] = true;
            q.push({now + a, cost + 1});
        }
        if(now - b >= 0 && !visited[now - b]){
            visited[now - b] = true;
            q.push({now - b, cost + 1});
        }
        if(now + b <= 100000 && !visited[now + b]){
            visited[now + b] = true;
            q.push({now + b, cost + 1});
        }
        if(now * a <= 100000 && !visited[now * a]){
            visited[now * a] = true;
            q.push({now * a, cost + 1});
        }
        if(now * b <= 100000 && !visited[now * b]){
            visited[now * b] = true;
            q.push({now * b, cost + 1});
        }
    }
}

int main(void){
    cin >> a >> b >> n >> m;
    cout << bfs(n, m) << '\n';
    return 0;
}