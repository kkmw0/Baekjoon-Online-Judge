#include <iostream>

using namespace std;

int n;

int main(void){
    cin >> n;

    int result = 1;
    for(int i = n; i > 1; i--) result *= i;
    cout << result << '\n';
    return 0;
}