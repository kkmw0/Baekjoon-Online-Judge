#include <iostream>
#include <algorithm>

using namespace std;

int a, b, n, min_value = 1e9;
int button[5];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> n;
    for(int i = 0; i < n; i++){
        cin >> button[i];
        min_value = min(min_value, abs(b - button[i]) + 1);
    }
    cout << min(min_value, abs(b - a)) << '\n';
    return 0;
}