#include <iostream>

using namespace std;

int n, k;
int d[31][31];

int main(void){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        d[i][1] = 1; d[i][i] = 1;
    }
    for(int i = 3; i <= n; i++){
        for(int j = 2; j < i; j++){
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }
    cout << d[n][k] << '\n';
    return 0;
}