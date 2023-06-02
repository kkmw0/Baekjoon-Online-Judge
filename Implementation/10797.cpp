#include <iostream>

using namespace std;

int n, result;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < 5; i++){
        int x;
        cin >> x;
        if(x == n) result++;
    }
    cout << result << '\n';
    return 0;
}