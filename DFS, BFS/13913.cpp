#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int path[100001];
bool visited[100001];
vector<int> result;

int bfs(int start){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    path[start] = 0;

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(now == k) return cost;

        if(now + 1 <= 100000 && !visited[now + 1]){
            path[now + 1] = now;
            visited[now + 1] = true;
            q.push({now + 1, cost + 1});
        }
        if(now - 1 >= 0 && !visited[now - 1]){
            path[now - 1] = now;
            visited[now - 1] = true;
            q.push({now - 1, cost + 1});
        }
        if(now << 1 <= 100000 && !visited[now << 1]){
            path[now << 1] = now;
            visited[now << 1] = true;
            q.push({now << 1, cost + 1});
        }
    }
}

void solve(){
    int cnt = bfs(n);
    cout << cnt << '\n';

    int idx = k;
    result.push_back(k);
    while(cnt--){
        result.push_back(path[idx]);
        idx = path[idx];
    }

    reverse(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++) cout << result[i] << ' ';
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    solve();
    return 0;
}