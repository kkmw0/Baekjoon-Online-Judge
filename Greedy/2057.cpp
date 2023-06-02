#include <iostream>

using namespace std;

long long n;
long long fact_arr[21];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    fact_arr[0] = 1, fact_arr[1] = 1, fact_arr[2] = 2;
    for(int i = 3; i <= 20; i++) fact_arr[i] = i * fact_arr[i - 1];

    bool flag = false;
    for(int i = 20; i >= 0; i--){
        if(n >= fact_arr[i]){
            n -= fact_arr[i];
            flag = true;
        }
    }
    if(n == 0 && flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}