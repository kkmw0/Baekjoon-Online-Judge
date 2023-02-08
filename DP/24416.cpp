#include <iostream>

using namespace std;

int n;
long long d[41];

int main(void){
    cin >> n;
    d[1] = d[2] = 1;
    for(int i = 3; i <= n; i++){
        d[i] = d[i - 2] + d[i - 1];
    }
    cout << d[n] << ' ' << n - 2 << '\n';
    return 0;
}