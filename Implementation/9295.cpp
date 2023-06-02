#include <iostream>

using namespace std;

int t, v, e;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> v >> e;
        cout << 2 + e - v << '\n';
    }
    return 0;
}