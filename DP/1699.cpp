#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[100001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    d[1] = 1;
    for(int i = 2; i <= n; i++){
        int min_value = 1e9;
        for(int j = 1; j * j <= i; j++){
            int now = i - j * j;
            min_value = min(min_value, d[now]);
        }
        d[i] = min_value + 1;
    }
    cout << d[n] << '\n';
    return 0;
}