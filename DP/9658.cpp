#include <iostream>

using namespace std;

int n;
string d[1001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    d[1] = "CY", d[2] = "SK", d[3] = "CY", d[4] = "SK";
    for(int i = 5; i <= n; i++){
        if(d[i - 1] == "CY" || d[i - 3] == "CY" || d[i - 4] == "CY") d[i] = "SK";
        else d[i] = "CY";
    }
    cout << d[n] << '\n';
    return 0;
}