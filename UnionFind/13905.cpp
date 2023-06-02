#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, s, e, result = 1e9;
int parent[100001];
vector<pair<int, pair<int, int>>> graph;

void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
}

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.first > b.first;
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

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> e;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
    sort(graph.begin(), graph.end(), cmp);

    init();
    for(int i = 0; i < m; i++){
        int cost = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if(find_Parent(a) != find_Parent(b)){
            union_Parent(a, b);
        }

        if(find_Parent(s) == find_Parent(e)){
            result = cost;
            break;
        }
    }
    if(result == 1e9) cout << 0 << '\n';
    else cout << result << '\n';
    return 0;
}