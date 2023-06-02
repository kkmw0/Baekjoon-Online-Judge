#include <iostream>

using namespace std;

int n, x, result;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        result += x;
    }
    cout << result - n + 1 << '\n';
    return 0;
}