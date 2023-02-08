#include <iostream>

using namespace std;

int n;
long long result[81];

int main(void){
    cin >> n;
    result[1] = 4; result[2] = 6;
    for(int i = 3; i <= n; i++){
        result[i] = result[i - 1] + result[i - 2];
    }
    cout << result[n] << '\n';
    return 0;
}