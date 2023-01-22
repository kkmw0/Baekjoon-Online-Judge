#include <iostream>

using namespace std;

int n, idx, cnt, tmp;
string str;

int main(void){
    cin >> n >> str;

    while((tmp = (int)str.find("LL", idx)) != -1){
        cnt++;
        idx = tmp + 2;
    }

    if(cnt <= 1) cout << str.size() << '\n';
    else cout << str.size() - cnt + 1 << '\n';
    return 0;
}