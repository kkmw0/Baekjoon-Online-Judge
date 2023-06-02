#include <iostream>

using namespace std;

int n, result;
int arr[501][501];
int d[501][501];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    d[1][1] = arr[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1) d[i][j] = d[i - 1][j] + arr[i][j];
            else if(j == i) d[i][j] = d[i - 1][j - 1] + arr[i][j];
            else d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + arr[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        if(d[n][i] > result) result = d[n][i];
    }
    cout << result << '\n';
    return 0;
}