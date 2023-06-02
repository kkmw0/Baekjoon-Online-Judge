#include <iostream>

using namespace std;

long long a, b;

int main(void){
    ios::sync_with_stdio(0); cout.tie(0);
    cin >> a >> b;
    if(a > b){
        if(a - b == 1) cout << 0 << '\n';
        else{
            cout << a - b - 1 << '\n';
            for(long long i = b + 1; i < a; i++) cout << i << ' ';
        }
    }
    else{
        if(a == b || b - a == 1) cout << 0 << '\n';
        else{
            cout << b - a - 1 << '\n';
            for(long long i = a + 1; i < b; i++) cout << i << ' ';
        }
    }
    return 0;
}