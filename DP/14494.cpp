#include <iostream>

using namespace std;

int n, m;
long long result;
long long d[1001][1001];

int main(void){
    cin >> n >> m;

    for(int i = 0; i <= n; i++) d[n - i][1] = 1;
    for(int i = 0; i <= m; i++) d[1][m - i] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            d[i][j] = d[i - 1][j] + d[i][j - 1] + d[i - 1][j - 1];
            if(d[i][j] >= 1000000007) d[i][j] %= 1000000007;
        }
    }
    cout << d[n][m] << '\n';
    return 0;
}