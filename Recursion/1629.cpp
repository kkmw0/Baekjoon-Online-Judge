#include <iostream>

typedef unsigned long long ll;
using namespace std;

ll a, b, c;

ll solve(ll x, ll p){
    if(p == 0) return 1;

    if(p % 2 == 0){
        ll res = solve(x, p / 2);
        return res * res % c;
    }
    else{
        return (x * solve(x, p - 1)) % c;
    }
}

int main(){
    cin >> a >> b >> c;
    ll result = solve(a, b) % c;
    cout << result << '\n';
    return 0;
}