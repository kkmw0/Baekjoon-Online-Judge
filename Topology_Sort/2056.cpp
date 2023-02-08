#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int time[10001];
int indegree[10001];
int result[10001];
vector<int> graph[10001];

void Topology_Sort(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        result[i] = time[i];
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = 0; i < graph[now].size(); i++){
            result[graph[now][i]] = max(result[graph[now][i]], result[now] + time[graph[now][i]]);
            indegree[graph[now][i]]--;
            if(indegree[graph[now][i]] == 0){
                q.push(graph[now][i]);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t, k;
        cin >> t >> k;
        time[i] = t;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            graph[x].push_back(i);
            indegree[i]++;
        }
    }
    Topology_Sort();
    cout << *max_element(result, result + n + 1) << '\n';
    return 0;
}