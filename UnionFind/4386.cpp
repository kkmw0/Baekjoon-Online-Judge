#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int parent[101];
vector<pair<int, pair<double, double>>> pos;
vector<pair<double, pair<int, int>>> graph;

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
    cin >> n;
    for(int i = 0; i <= n; i++) parent[i] = i;

    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        pos.push_back({i, {x, y}});
    }

    for(int i = 0; i < n; i++){
        int p_idx = pos[i].first;
        double p_x = pos[i].second.first;
        double p_y = pos[i].second.second;
        for(int j = i + 1; j < pos.size(); j++){
            int c_idx = pos[j].first;
            double c_x = pos[j].second.first;
            double c_y = pos[j].second.second;
            double tmp = pow((p_x - c_x), 2) + pow((p_y - c_y), 2);
            double dist = sqrt(tmp);
            graph.push_back({dist, {p_idx, c_idx}});
        }
    }
    sort(graph.begin(), graph.end());

    double result = 0;
    for(int i = 0; i < graph.size(); i++){
        double cost = graph[i].first;
        double a = graph[i].second.first;
        double b = graph[i].second.second;

        if(find_Parent(a) != find_Parent(b)){
            result += cost;
            union_Parent(a, b);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << result << '\n';
    return 0;
}