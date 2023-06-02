#include <iostream>

using namespace std;

int n;
string d[1001];

int main(void){
    cin >> n;
    d[1] = d[3] = d[4] = d[5] = "SK"; 
    d[2] = "CY";
    for(int i = 6; i <= n; i++){
        //d[i]가 SK의 차례면 d[i - 1], d[i - 3], d[i - 4]는 CY의 차례
        //따라서 d[i - 1], d[i - 3], d[i - 4]에서 하나라도 CY여야 SK가 이김
        if(d[i - 1] == "CY" || d[i - 3] == "CY" || d[i - 4] == "CY") d[i] = "SK";
        else d[i] = "CY";
    }
    cout << d[n] << '\n';
    return 0;
}