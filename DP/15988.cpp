#include <iostream>

using namespace std;

int t, n;
long long d[1000001];

void init(){
    d[1] = 1, d[2] = 2, d[3] = 4;
    for(int i = 4; i <= 1000000; i++){
        d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % 1000000009;
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        cin >> n;
        cout << d[n] << '\n';
    }
    return 0;
}