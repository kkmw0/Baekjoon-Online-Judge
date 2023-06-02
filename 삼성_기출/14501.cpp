#include <iostream>

using namespace std;

int n;
int t[17], p[17], d[17];

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> t[i] >> p[i];
    for(int i = 1; i <= n; i++){
        d[i + 1] = max(d[i], d[i + 1]);
        if(i + t[i] <= n + 1) d[i + t[i]] = max(d[i + t[i]], p[i] + d[i]);
    }
    cout << d[n + 1] << '\n';
    return 0;
}