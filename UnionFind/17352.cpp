#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int parent[300001];
vector<pair<int, int>> graph;

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
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 0; i < n - 2; i++){
        int a, b;
        cin >> a >> b;
        union_Parent(a, b);
    }

    for(int i = 2; i <= n; i++){
        if(find_Parnet(1) != find_Parnet(i)){
            cout << 1 << ' ' << i << '\n';
            break;
        }
    }
    return 0;
}