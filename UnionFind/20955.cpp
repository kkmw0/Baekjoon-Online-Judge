#include <iostream>

using namespace std;

int n, m, cycle, result;
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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    init();
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(find_Parent(a) != find_Parent(b)) union_Parent(a, b);
        else cycle++;
    }

    int pivot = parent[1];
    for(int i = 2; i <= n; i++){
        if(find_Parent(i) != pivot){
            result++;
            union_Parent(i, pivot);
        }
    }
    cout << result + cycle << '\n';
    return 0;
}