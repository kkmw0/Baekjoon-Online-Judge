#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int parent[1001];
vector<pair<int, pair<int, int>>> graph;

int find_Parnet(int x){
    if(x == parent[x]) return x;
    return parent[x] = find_Parnet(parent[x]);
}

void union_Parent(int a, int b){
    a = find_Parnet(a);
    b = find_Parnet(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i <= n; i++) parent[i] = i;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            if(j <= i) continue;
            else graph.push_back({x, {i, j}});
        }
    }
    sort(graph.begin(), graph.end());

    long long result = 0;
    for(int i = 0; i < graph.size(); i++){
        int cost = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if(find_Parnet(a) != find_Parnet(b)){
            union_Parent(a, b);
            result += cost;
        }
    }
    cout << result << '\n';
    return 0;
}