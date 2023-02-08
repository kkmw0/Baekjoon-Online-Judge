#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[17], t[17], p[17];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> p[i];
    }

    for(int i = 1; i <= n; i++){
        d[i + 1] = max(d[i], d[i + 1]);
        if(i + t[i] <= n + 1) d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
    }
    cout << d[n + 1] << '\n';
    return 0;
}