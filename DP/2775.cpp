#include <iostream>

using namespace std;

int t, k, n;
int d[15][15];

void init(){
    for(int i = 0; i <= 14; i++){
        for(int j = 0; j <= 14; j++){
            d[i][j] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        init();

        cin >> k >> n;
        for(int i = 1; i <= n; i++) d[0][i] = i;

        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                for(int l = 1; l <= j; l++){
                    d[i][j] += d[i - 1][l];
                }
            }
        }
        cout << d[k][n] << '\n';
    }
    return 0;
}