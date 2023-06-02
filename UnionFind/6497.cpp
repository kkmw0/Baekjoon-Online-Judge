#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int parent[200001];

int find_Parent(int x){
    if(x == parent[x]) return x;
    return parent[x] = find_Parent(parent[x]);
}

void union_Parent(int a, int b){
    a = find_Parent(a);
    b = find_Parent(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        int s = 0, result = 0;
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 0; i < n; i++) parent[i] = i;

        vector<pair<int, pair<int, int>>> graph;
        for(int i = 0; i < m; i++){
            int a, b, cost;
            cin >> a >> b >> cost;
            s += cost;
            graph.push_back({cost, {a, b}});
        }
        sort(graph.begin(), graph.end());

        for(int i = 0; i < m; i++){
            int cost = graph[i].first;
            int a = graph[i].second.first;
            int b = graph[i].second.second;

            if(find_Parent(a) != find_Parent(b)){
                result += cost;
                union_Parent(a, b);
            }
        }
        cout << s - result << '\n';
    }
    return 0;
}