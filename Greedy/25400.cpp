#include <iostream>

using namespace std;

int n, x, result, num = 1;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(cin >> x){
        if(x == num) num++;
        else result++;
    }
    cout << result << '\n';
    return 0;
}