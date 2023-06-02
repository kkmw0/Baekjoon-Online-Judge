#include <iostream>

using namespace std;

int x, result;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 5; i++){
        cin >> x;
        result += x;
    }
    cout << result << '\n';
    return 0;
}