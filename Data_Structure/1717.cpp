#include <iostream>

using namespace std;

int n, m;
int parent[1000001];

int find_Parent(int x){
    if(x == parent[x]) return x;
    return parent[x] = find_Parent(parent[x]);
}

void Union_Parent(int a, int b){
    a = find_Parent(a);
    b = find_Parent(b);
    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 0; i < m; i++){
        int oper, a, b;
        cin >> oper >> a >> b;
        
        if(oper == 0) Union_Parent(a, b);
        else{
            if(find_Parent(a) != find_Parent(b)) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}