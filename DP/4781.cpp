#include <iostream>
#include <algorithm>

using namespace std;

int n;
int c[5001], p[5001];
int d[10001];
double m;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        fill_n(d, 10001, 0);

        cin >> n >> m;
        if(n == 0 && m == 0.00) break;
        int money = static_cast<int>(m * 100 + 0.5);

        for(int i = 0; i < n; i++){
            int x; double y;
            cin >> c[i] >> y;
            p[i] = static_cast<int>(y * 100 + 0.5);
        }

        for(int i = 0; i < n; i++){
            for(int j = 1; j <= money; j++){
                if(p[i] <= j) d[j] = max(d[j], d[j - p[i]] + c[i]);
            }
        }
        cout << d[money] << '\n';
    }
    return 0;
}