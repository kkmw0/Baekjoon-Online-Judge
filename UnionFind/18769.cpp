#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, r, c, result;
int parent[250001];
vector<pair<int, pair<int, int>>> graph;

void init(){
    result = 0;
    graph.clear();
    for(int i = 0; i <= r * c; i++){
        parent[i] = i;
    }
}

void input(){
    cin >> r >> c;

    init();
    int idx = 1;
    for(int i = 1; i <= r; i++, idx++){
        for(int j = 1; j < c; j++, idx++){
            int x;
            cin >> x;
            graph.push_back({x, {idx, idx + 1}});
        }
    }

    int idx_1 = 1, idx_2 = c + 1;
    for(int i = 1; i < r; i++){
        for(int j = 1; j <= c; j++, idx_1++, idx_2++){
            int x;
            cin >> x;
            graph.push_back({x, {idx_1, idx_2}});
        }
    }
    sort(graph.begin(), graph.end());
}

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

void solve(){
    for(int i = 0; i < graph.size(); i++){
        int cost = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if(find_Parent(a) != find_Parent(b)){
            result += cost;
            union_Parent(a, b);
        }
    }
    cout << result << '\n';
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        input();
        solve();
    }
    return 0;
}