#include <iostream>
#include <queue>

using namespace std;

int a, b, n;
int button[5];

int bfs(int start, int end){
    bool visited[1000] = {false, };
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    for(int i = 0; i < n; i++){
        if(!visited[button[i]]){
            visited[button[i]] = true;
            q.push({button[i], 1});
        }
    }

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(now == end)  return cost;

        if(now + 1 < 1000 && !visited[now + 1]){
            visited[now + 1] = true;
            q.push({now + 1, cost + 1});
        }
        if(now - 1 >= 0 && !visited[now - 1]){
            visited[now - 1] = true;
            q.push({now - 1, cost + 1});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> n;
    for(int i = 0; i < n; i++) cin >> button[i];
    cout << bfs(a, b) << '\n';
    return 0;
}