#include <iostream>
#include <algorithm>

using namespace std;

string str1, str2;
int dp[1001][1001];

int main(){
    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << dp[n][m] << '\n';
}