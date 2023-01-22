#include <iostream>

using namespace std;

int n;

int main(void){
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        cout << (i % 2 == 1 ? 1 : 2) << ' ';
    }
    cout << (n % 2 == 0 ? 2 : 3) << '\n';
    return 0;
}