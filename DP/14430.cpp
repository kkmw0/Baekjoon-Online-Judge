#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[301][301], d[301][301];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            d[i][j] = max({d[i][j], d[i - 1][j], d[i][j - 1]}) + arr[i][j];
        }
    }
    cout << d[n][m] << '\n';
    return 0;
}