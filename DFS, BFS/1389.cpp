#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, m, s, answer, result = 1e9;
int d[101];
bool visited[101];
vector<int> graph[101];

void init(){
    s = 0;
    fill_n(d, 101, INF);
    fill_n(visited, 101, false);
}

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

    for(int i = 1; i <= n; i++){
        init();
        bfs(i);
        for(int j = 1; j <= n; j++) s += d[j];
        if(s < result) {
            result = s;
            answer = i;
        }
    }
    cout << answer << '\n';
    return 0;
}