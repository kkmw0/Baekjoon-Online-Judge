#include <iostream>
#include <algorithm>

using namespace std;

int sum;
string str;

int main(void){
    cin >> str;
    sort(str.begin(), str.end(), greater<int>());

    bool flag = false;
    if(str[str.size() - 1] == '0') flag = true;
    for(int i = 0; i < str.size(); i++) sum += str[i] - '0';

    if(flag){
        if(sum % 3 == 0) cout << str << '\n';
        else cout << -1 << '\n';
    }
    else cout << -1 << '\n';
    
    return 0;
}