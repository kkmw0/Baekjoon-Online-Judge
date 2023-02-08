#include <iostream>

using namespace std;

int t, n;
long long d[101];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    d[1] = 1; d[2] = 1; d[3] = 1; d[4] = 2; d[5] = 2;
    for(int i = 6; i <= 100; i++){
        d[i] = d[i - 5] + d[i - 1];
    }
    for(int test_case = 0; test_case < t; test_case++){
        cin >> n;
        cout << d[n] << '\n';
    }
    return 0;
}