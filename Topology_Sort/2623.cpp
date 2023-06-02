#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int indegree[1001];
vector<int> graph[1001];

void Topology_sort(){
    vector<int> result;
    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        result.push_back(now);
        q.pop();

        for(int i = 0; i < graph[now].size(); i++){
            int node = graph[now][i];
            indegree[node]--;
            if(indegree[node] == 0) q.push(node);
        }
    }

    bool flag = false;
    for(int i = 1; i <= n; i++){
        if(indegree[i] != 0){
            flag = true;
            break;
        }
    }

    if(flag) cout << 0 << '\n';
    else{
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << '\n';
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int num, pivot;
        cin >> num >> pivot;
        for(int j = 0; j < num - 1; j++){
            int x;
            cin >> x;
            graph[pivot].push_back(x);
            indegree[x]++;
            pivot = x;
        }
    }
    Topology_sort();
    return 0;
}