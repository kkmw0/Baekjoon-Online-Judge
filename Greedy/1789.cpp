#include <iostream>

using namespace std;

long long n;

int main(void){
    cin >> n;
    for(int i = 1; ; i++){
        n -= i;
        if(n < 0){
            cout << i - 1 << '\n';
            break;
        }
    }
    return 0;
}