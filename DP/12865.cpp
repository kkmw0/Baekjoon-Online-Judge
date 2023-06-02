#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int w[101], v[101];
int d[101][101];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(w[i] > j) d[i][j] = d[i - 1][j];
            else d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << d[n][k] << '\n';
    return 0;
}