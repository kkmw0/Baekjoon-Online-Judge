#include <iostream>

using namespace std;

long long n;
long long fibo[51];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    fibo[0] = 1, fibo[1] = 1;
    for(int i = 2; i <= n; i++){
        fibo[i] = (fibo[i - 1] + fibo[i - 2] + 1) % 1000000007;
    }
    cout << fibo[n] << '\n';
    return 0;
}