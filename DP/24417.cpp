#include <iostream>
#include <algorithm>

using namespace std;

int n, last1, last2, tmp;
long long result;

int main(void){
    cin >> n;
    last1 = 3; last2 = 2;
    for(int i = 5; i <= n; i++){
        result = last1 + last2;
        if(result >= 1000000007) result -= 1000000007;
        tmp = last1; last1 = result; last2 = tmp;
    }
    cout << result << ' ' << n - 2 << '\n';
    return 0;
}