#include <iostream>
#include <queue>
#include <map>

using namespace std;

long long a, b;
map<long long, bool> visited;

void bfs(long long x){
    queue<pair<long long, int>> q;
    q.push({x, 0});

    while(!q.empty()){
        long long now = q.front().first;
        int d = q.front().second;
        q.pop();

        if(now == b){
            cout << d + 1 << '\n';
            return;
        }
        if((now << 1) <= b && !visited[now * 2]){
            visited[now << 1] = true;
            q.push({now << 1, d + 1});
        }
        if(now * 10 + 1 <= b && !visited[now * 10 + 1]){
            visited[now * 10 + 1] = true;
            q.push({now * 10 + 1, d + 1});            
        }
    }
    cout << -1 << '\n';
}

int main(void){
    cin >> a >> b;
    bfs(a);
    return 0;
}