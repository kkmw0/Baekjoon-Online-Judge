#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int parent[100001];
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

bool check(){
    for(int i = 2; i <= n; i++){
        if(find_Parnet(1) != find_Parnet(i)) return false;
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;

    long long s = 0;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        s += c;
        graph.push_back({c, {a, b}});
    }
    sort(graph.begin(), graph.end());

    long long result = 0;
    for(int i = 0; i < m; i++){
        int cost = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if(find_Parnet(a) != find_Parnet(b)){
            result += cost;
            union_Parent(a, b);
        }
    }

    if(check()) cout << s - result << '\n';
    else cout << -1 << '\n';
    return 0;
}