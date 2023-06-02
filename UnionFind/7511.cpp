#include <iostream>
#include <vector>

using namespace std;

int t, n, k, m;
int parent[1000001];

void init(){
    for(int i = 0; i <= 1000000; i++) parent[i] = i;
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
    init();
    cin >> t;
    for(int test_case = 1; test_case <= t; test_case++){
        cin >> n >> k;
        for(int i = 0; i < k; i++){
            int a, b;
            cin >> a >> b;
            union_Parent(a, b);
        }
        cin >> m;
        cout << "Scenario " << test_case << ":\n";
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            if(find_Parent(u) != find_Parent(v)) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        for(int i = 0; i <= n; i++) parent[i] = i;
        cout << '\n';
    }
    return 0;
}