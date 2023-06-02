#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
string d[101][101];

string add(string a, string b){
    string result;
    int len_a = a.length();
    int len_b = b.length();
    int value = 0;

    for(int i = 0; i < len_a || i < len_b; i++){
        if(i < len_a) value += a[len_a - i - 1] - '0';
        if(i < len_b) value += b[len_b - i - 1] - '0';
        result += (value % 10) + '0';
        value /= 10;
    }
    if(value != 0) result += value + '0';
    reverse(result.begin(), result.end());
    return result;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i <= 100; i++){
        d[i][0] = "1";
        d[i][i] = "1";
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            d[i][j] = add(d[i - 1][j - 1], d[i - 1][j]);
        }
    }
    cout << d[n][m] << '\n';
    return 0;
}