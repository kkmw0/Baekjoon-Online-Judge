#include <iostream>

using namespace std;

int n;
long long d[36];

int main(void){
    cin >> n;
    d[0] = 1; d[1] = 1;
    for(int i = 2; i <= n; i++){
        long long s = 0;
        for(int j = i - 1, cnt = 0; j >= 0; j--, cnt++){
            s += d[j] * d[cnt];
        }
        d[i] = s;
    }
    cout << d[n] << '\n';
    return 0;
}