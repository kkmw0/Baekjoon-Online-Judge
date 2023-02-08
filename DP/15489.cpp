#include <iostream>

using namespace std;

int r, c, w;
long long s;
int d[31][31];

int main(void){
    cin >> r >> c >> w;
    for(int i = 1; i <= r + w - 1; i++) {
        d[i][1] = 1; d[i][i] = 1;
    }
    for(int i = 3; i <= r + w - 1; i++){
        for(int j = 2; j < i; j++){
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }
    for(int i = r, cnt = 0; i <= r + w - 1; i++, cnt++){
        for(int j = 0; j <= cnt; j++){
            s += d[i][j + c];
        }
    }
    cout << s << '\n';
    return 0;
}