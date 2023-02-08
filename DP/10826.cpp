#include <iostream>
#include <algorithm>

using namespace std;

int n;
string d[10001];

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
    ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    d[0] = "0"; d[1] = "1"; d[2] = "1";
    for(int i = 3; i <= n; i++){
        d[i] = add(d[i - 1], d[i - 2]);
    }
    cout << d[n] << '\n';
    return 0;
}