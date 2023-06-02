#include <iostream>

using namespace std;

int n, total, result;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 4; i++){
        int x, y;
        cin >> x >> y;
        total += y - x;
        if(total > result) result = total;
    }
    cout << result << '\n';
    return 0;
}