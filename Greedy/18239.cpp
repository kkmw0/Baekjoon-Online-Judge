#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string str;

int main(void){
    cin >> str;

    int cnt = 0;
    int pos = 0;
    for(int i = 0; i < str.size(); i++){
        int now = abs((str[i] - 'A') - pos);
        cnt += min(now, (26 - now) % 26);
        pos = str[i] - 'A';
    }
    cout << cnt << '\n';
    return 0;
}