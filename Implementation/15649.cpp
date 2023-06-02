#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool used[9];

void solve(int k){
    if(k == m){
        for(int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            arr[k] = i;
            used[i] = true;
            solve(k + 1);
            used[i] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    solve(0);
    return 0;
}