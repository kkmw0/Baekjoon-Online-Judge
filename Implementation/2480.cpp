#include <iostream>

using namespace std;

int a, b, c, result;

int main(void){
    cin >> a >> b >> c;
    if(a == b && b == c) result = 10000 + a * 1000;
    else if(a == b || b == c || a == c){
        if(a == b) result = 1000 + a * 100;
        else if(b == c) result = 1000 + b * 100;
        else result = 1000 + a * 100;
    }
    else{
        int max_value = 0;
        if(a > b && a > c) max_value = a;
        else if(b > a && b > c) max_value = b;
        else max_value = c;
        result = max_value * 100;
    }
    cout << result << '\n';
    return 0;
}