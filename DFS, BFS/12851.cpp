#include <iostream>
#include <queue>

using namespace std;

int n, k, cnt, result = 1e9;
bool visited[100001];

void bfs(int start, int end){
    queue<pair<int, int>> q;
    q.push({start, 0});

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        visited[now] = true;
        q.pop();

        if(cost > result) break;

        if(now == end){
            result = cost;
            cnt++;
            continue;
        }

        if(now + 1 <= 100000 && !visited[now + 1]) q.push({now + 1, cost + 1});
        if(now - 1 >= 0 && !visited[now - 1]) q.push({now - 1, cost + 1});
        if(now << 1 <= 100000 && !visited[now << 1]) q.push({now << 1, cost + 1});
    }
}

int main(void){
    cin >> n >> k;
    bfs(n, k);
    cout << result << '\n' << cnt << '\n';
    return 0;
}