#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, m, idx, result, cnt = 1;
int d[20001];
bool visited[20001];
vector<int> graph[20001];

void bfs(int start){
    queue<pair<int, int>> q;
    q.push({start, 0});
    d[start] = 0;
    visited[start] = true;

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        for(int i = 0; i < graph[now].size(); i++){
            int x = graph[now][i];
            if(!visited[x] && cost + 1 < d[x]){
                visited[x] = true;
                d[x] = cost + 1;
                q.push({x, cost + 1});
            }
        }
    }

}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    fill_n(d, 20001, INF);
    bfs(1);

    for(int i = 1; i <= n; i++){
        if(d[i] >= result){
            if(result == d[i]) cnt++;
            else {
                idx = i;
                cnt = 1;
            }
            result = d[i];
        }
    }
    cout << idx << ' ' << result << ' ' << cnt << '\n';
    return 0;
}