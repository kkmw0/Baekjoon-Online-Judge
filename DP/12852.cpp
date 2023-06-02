#include <iostream>

using namespace std;

int n;
int d[1000001];
int mv[1000001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    d[1] = 0, mv[1] = 1;
    for(int i = 2; i <= n; i++){
        d[i] = d[i - 1] + 1; mv[i] = i - 1;
        if(i % 2 == 0 && d[i] > d[i / 2] + 1){
            d[i] = d[i / 2] + 1;
            mv[i] = i / 2;
        }
        if(i % 3 == 0 && d[i] > d[i / 3] + 1){
            d[i] = d[i / 3] + 1;
            mv[i] = i / 3;
        }
    }
    cout << d[n] << '\n';
    cout << n << ' ';
    for(int i = n; i != 1; ){
        int idx = mv[i];
        cout << idx << ' ';
        i = idx;
    }
    return 0;
}