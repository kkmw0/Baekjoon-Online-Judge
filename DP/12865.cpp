#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int w[101], v[101];
int dp[101][100001];

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j < w[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
        }
    }

    cout << dp[n][k] << '\n';
    return 0;
}