#include <iostream>

using namespace std;

int n, min_value = 1e9, result, cnt;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 7; i++){
        int x;
        cin >> x;
        if(x % 2 == 1){
            cnt++;
            result += x;
            if(x < min_value) min_value = x;
        }
    }
    if(cnt == 0) cout << -1 << '\n';
    else cout << result << '\n' << min_value << '\n';
    return 0;
}