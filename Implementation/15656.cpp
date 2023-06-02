#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int tmp[8], arr[8];

void solve(int k){
    if(k == m){
        for(int i = 0; i < m; i++) cout << tmp[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        tmp[k] = arr[i];
        solve(k + 1);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    solve(0);
    return 0;
}