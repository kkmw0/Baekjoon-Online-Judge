#include <iostream>

using namespace std;

int n, m, pivot, result;
int parent[100001];

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

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(00);
    cin >> n >> m;

    init();
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        union_Parent(a, b);
    }

    cin >> pivot;
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        
        if(find_Parent(pivot) != find_Parent(x)) result++;
        pivot = x;
    }
    cout << result << '\n';
    return 0;
}