#include <iostream>

using namespace std;

int t;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++){
        string str; cin >> str;
        cout << str[0] << str[str.size() - 1] << '\n';
    }
    return 0;
}