#include <iostream>

using namespace std;

int n, s;

int main(void){
    cin >> n;
    for(int i = 1; i < n; i++) s += i;
    cout << s << '\n';
    return 0;
}