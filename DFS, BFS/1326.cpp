#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, a, b;
int arr[10001];
bool visited[10001];

int bfs(int start, int end){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()){
        int now = q.front().first;
        int d = q.front().second;
        int jump = arr[now];
        q.pop();

        if(now == end) return d;

        for(int i = now + jump; i <= n; i += jump){
            if(!visited[i]){
                visited[i] = true;
                q.push({i, d + 1});
            }
        }
        for(int i = now - jump; i >= 1; i -= jump){
            if(!visited[i]){
                visited[i] = true;
                q.push({i, d + 1});
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cin >> a >> b;
    cout << bfs(a, b) << '\n';
    return 0;
}