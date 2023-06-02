#include <iostream>

using namespace std;

int total;

int main(void){
    cin >> total;
    for(int i = 0; i < 9; i++){
        int x;
        cin >> x;
        total -= x;
    }
    cout << total << '\n';
    return 0;
}