#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[100001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) d[i] = 1e9;

    d[1] = 1, d[2] = 1, d[5] = 1, d[7] = 1;
    for(int i = 3; i <= n; i++){
        d[i] = min(d[i], d[i - 1] + 1);
        if(i - 2 >= 1) d[i] = min(d[i], d[i - 2] + 1);
        if(i - 5 >= 1) d[i] = min(d[i], d[i - 5] + 1);
        if(i - 7 >= 1) d[i] = min(d[i], d[i - 7] + 1);
    }
    cout << d[n] << '\n';
    return 0;
}