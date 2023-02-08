#include <iostream>

using namespace std;

int t, n, m;
int d[31][31];

int combination(int c, int r){
    if(d[c][r] != 0) return d[c][r];
    if(c == r || r == 0) return 1;
    else{
        d[c][r] = combination(c - 1, r - 1) + combination(c - 1, r);
        return d[c][r];
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        cout << combination(m, n) << '\n';
    }
    return 0;
}