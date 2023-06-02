#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m, result;
int parent[21];
vector<pair<int, pair<int, int>>> graph;

void init(){
    result = 0;
    graph.clear();
    for(int i = 1; i <= 20; i++){
        parent[i] = i;
    }
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
    cin >> t;
    for(int test_case = 1; test_case <= t; test_case++){
        init();
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            graph.push_back({c, {a, b}});
        }
        sort(graph.begin(), graph.end());

        for(int i = 0; i < m; i++){
            int cost = graph[i].first;
            int a = graph[i].second.first;
            int b = graph[i].second.second;

            if(find_Parent(a) != find_Parent(b)){
                union_Parent(a, b);
                result += cost;
            }
        }

        cout << "Case #" << test_case << ": " << result << " meters\n";
    }
    return 0;
}