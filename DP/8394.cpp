#include <iostream>

using namespace std;

long long n, result;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    int first = 1, second = 2, result = 0;
    for(int i = 3; i <= n; i++){
        result = (first + second) % 10;
        first = second;
        second = result;
    }
    if(n == 1) cout << 1 << '\n';
    else if(n == 2) cout << 2 << '\n';
    else cout << result << '\n';
    return 0;
}