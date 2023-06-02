#include <iostream>

using namespace std;

long long n, result;
long long f[2000001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    n += 1000000;

    f[999999] = 1, f[1000000] = 0, f[1000001] = 1;
    for(int i = 999998; i >= 0; i--){
        f[i] = (f[i + 2] - f[i + 1]) % 1000000000;
    }
    for(int i = 1000002; i <= n; i++){
        f[i] = (f[i - 2] + f[i - 1]) % 1000000000;
    }

    if(f[n] > 0) cout << 1 << '\n';
    else if(f[n] == 0) cout << 0 << '\n';
    else cout << -1 << '\n';
    cout << abs(f[n]) << '\n';
    return 0;
}