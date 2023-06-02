#include <iostream>
#include <vector>

using namespace std;

int n, m, result;
int parent[500001];

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
    cin >> n >> m;
    for(int i = 0; i <= n; i++) parent[i] = i;

    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;

        if(find_Parent(a) != find_Parent(b)) union_Parent(a, b);
        else{
            if(result == 0) result = i;
        }
    }
    cout << result << '\n';
    return 0;
}