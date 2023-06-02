#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, result;
int cost[10001], parent[10001];

void init(){
    for(int i = 1; i <= n; i++){
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

    if(cost[a] > cost[b]) parent[a] = b;
    else parent[b] = a;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> cost[i];

    init();
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        union_Parent(a, b);
    }

    for(int i = 1; i <= n; i++){
        if(parent[i] == i){
            result += cost[i];
        }
    }
    if(result <= k) cout << result << '\n';
    else cout << "Oh no\n";
    return 0;
}