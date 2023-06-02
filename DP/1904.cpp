#include <iostream>

using namespace std;

int n;
long long d[1000001];

int main(void){
    cin >> n;
    d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++){
        d[i] = (d[i - 1] + d[i - 2]) % 15746;
    }
    cout << d[n] << '\n';
    return 0;
}