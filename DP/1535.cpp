#include <iostream>

using namespace std;

int n;
int l[21], j[21];
int d[21][101];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> l[i];
    for(int i = 1; i <= n; i++) cin >> j[i];

    int result = 0;
    for(int i = 1; i <= n; i++){
        int now_l = l[i];
        for(int h = 0; h <= 100; h++){
            if(h + now_l < 100) d[i][h] = max(d[i - 1][h], d[i - 1][h + now_l] + j[i]);
            else d[i][h] = max(d[i][h], d[i - 1][h]);
            result = max(result, d[i][h]);
        }
    }
    cout << result << '\n';
    return 0;
}