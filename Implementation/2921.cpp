#include <iostream>

using namespace std;

int n, result;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j = i; j <= n; j++){
            result += (i + j);
        }
    }
    cout << result << '\n';
    return 0;
}