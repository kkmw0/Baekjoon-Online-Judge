#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int parent[1001];
vector<pair<int, pair<int, int>>> graph;

void init(){
    for(int i = 1; i <= 1000; i++){
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

bool check(){
    int pivot = parent[1];
    for(int i = 2; i <= n; i++){
        if(pivot != find_Parent(i)){
            return false;
        }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
    sort(graph.begin(), graph.end(), cmp);

    init();
    long long result = 0;
    for(int i = 0; i < m; i++){
        int cost = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if(find_Parent(a) != find_Parent(b)){
            result += cost;
            union_Parent(a, b);
        }
    }
    if(check()) cout << result << '\n';
    else cout << -1 << '\n';
    return 0;
}