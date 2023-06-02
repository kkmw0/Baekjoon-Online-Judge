#include <iostream>
#include <algorithm>

using namespace std;

int n;
int rgb[3][1000];
int d[3][1000];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
    }

    d[0][0] = rgb[0][0], d[1][0] = rgb[1][0], d[2][0] = rgb[2][0];
    for(int i = 1; i < n; i++){
        d[0][i] = min(d[1][i - 1], d[2][i - 1]) + rgb[0][i];
        d[1][i] = min(d[0][i - 1], d[2][i - 1]) + rgb[1][i];
        d[2][i] = min(d[0][i - 1], d[1][i - 1]) + rgb[2][i];
    }
    cout << min({d[0][n - 1], d[1][n - 1], d[2][n - 1]}) << '\n';
    return 0;
}