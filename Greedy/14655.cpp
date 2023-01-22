#include <iostream>

using namespace std;

int n, sum;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x < 0 ? -x : x;
    }
    cout << (sum << 1) << '\n';
    return 0;
}