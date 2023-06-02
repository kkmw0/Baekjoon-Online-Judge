#include <iostream>

using namespace std;

int n, k;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    int value = k * (k + 1) / 2;
    if(n < value) cout << -1 << '\n';
    else{
        bool flag = false;
        for(int i = value; i <= n; i += k){
            if(n == i) flag = true;
        }
        if(flag) cout << k - 1 << '\n';
        else cout << k << '\n';
    }
    return 0;
}