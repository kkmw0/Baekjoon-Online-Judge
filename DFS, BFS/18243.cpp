#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, k;
int visited[101];
vector<int> graph[101];

void bfs(int start){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 0;

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        for(int i = 0; i < graph[now].size(); i++){
            int x = graph[now][i];
            if(cost + 1 < visited[x]){
                visited[x] = cost + 1;
                q.push({x, cost + 1});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        fill_n(visited, 101, 1e9);
        bfs(i);

        for(int i = 1; i <= n; i++){
            if(visited[i] > 6){
                cout << "Big World!" << '\n';
                return 0;
            }
        }
    }
    cout << "Small World!" << '\n';
    return 0;
}