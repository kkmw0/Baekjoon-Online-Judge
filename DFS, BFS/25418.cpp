#include <iostream>

using namespace std;

int a, k, result;

int main(void){
    cin >> a >> k;
    while(a != k){
        if((k >> 1) >= a){
            if(k % 2 == 0) k /= 2;
            else k--;
        }
        else k--;
        result++;
    }
    cout << result << '\n';
}