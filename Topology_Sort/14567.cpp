#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int indegree[1001];
int result[1001];
vector<int> graph[1001];

void Topology_Sort(){
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) q.push({i, 1});
    }

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        result[now] = cost;
        q.pop();

        for(int i = 0; i < graph[now].size(); i++){
            indegree[graph[now][i]]--;
            if(indegree[graph[now][i]] == 0) {
                q.push({graph[now][i], cost + 1});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    Topology_Sort();
    for(int i = 1; i <= n; i++){
        cout << result[i] << ' ';
    }
    return 0;
}