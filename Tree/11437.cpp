#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int parent[50001], depth[50001];
vector<int> graph[50001];
vector<int> answer;

int LCA(int a, int b){
    if(depth[b] > depth[a]) swap(a, b);

    while(depth[a] != depth[b]){
        a = parent[a];
    }

    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}

void set_tree(int node, int pnode){
    parent[node] = pnode;
    depth[node] = depth[pnode] + 1;

    for(int i = 0; i < graph[node].size(); i++){
        int child = graph[node][i];
        if(child == pnode) continue;

        set_tree(child, node);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    set_tree(1, 0);

    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        int result = LCA(a, b);
        answer.push_back(result);
    }

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << '\n';
    }

    return 0;
}