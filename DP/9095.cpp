#include <iostream>

using namespace std;

int t, n;
int d[12];

int recur(int x){
    if(x == 1 || x == 0) return 1;
    else if(x == 2) return 2;
    
    if(d[x] != 0) return d[x];
    else return recur(x - 1) + recur(x - 2) + recur(x - 3);
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    d[0] = 0; d[1] = 1; d[2] = 2;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << recur(n) << '\n';
    }
    return 0;
}