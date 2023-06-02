#include <iostream>

using namespace std;

int t, p, q;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 1; test_case <= t; test_case++){
        long long d[10001] = {0, };
        cin >> p >> q;

        d[1] = 1, d[2] = 1;
        for(int i = 3; i <= p; i++){
            d[i] = (d[i - 1] + d[i - 2]) % q;
        }
        if(q == 1) cout << "Case #" << test_case << ": " << 0 << '\n';
        else cout << "Case #" << test_case << ": " << d[p] << '\n';
    }
    return 0;
}