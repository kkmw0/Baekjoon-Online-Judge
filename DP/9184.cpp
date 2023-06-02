#include <iostream>

using namespace std;

int a, b, c;
int d[21][21][21];

int calc(){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20){
        a = 20, b = 20, c = 20;
    }

    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            for(int k = 0; k <= c; k++){
                if(i == 0 || j == 0 || k == 0) d[i][j][k] = 1;
                else if(i < j && j < k) d[i][j][k] = d[i][j][k - 1] + d[i][j - 1][k - 1] - d[i][j - 1][k];
                else d[i][j][k] = d[i - 1][j][k] + d[i - 1][j - 1][k] + d[i - 1][j][k - 1] - d[i - 1][j - 1][k - 1];
            }
        }
    }
    return d[a][b][c];
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        cout << calc() << '\n';
    }
    return 0;
}