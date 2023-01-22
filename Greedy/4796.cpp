#include <iostream>
#include <algorithm>

using namespace std;

long long l, p, v, cnt;

int main(void){
    while(true){
        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0) break;
        cout << "Case " << ++cnt << ": " << v / p * l + min(v % p, l) << '\n';
    }
    return 0;
}