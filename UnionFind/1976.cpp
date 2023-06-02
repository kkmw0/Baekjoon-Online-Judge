#include <iostream>

using namespace std;

int n, m;
int plan[1001];
int parent[201];

void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
}

int findParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    init();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1) unionParent(i, j);
        }
    }
    for(int i = 1; i <= m; i++) cin >> plan[i];

    int tmp = parent[plan[1]];
    bool flag = false;
    for(int i = 2; i <= m; i++){
        int now = findParent(plan[i]);
        if(now != tmp){
            flag = true;
            break;
        }
        tmp = now;
    }

    if(flag) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}