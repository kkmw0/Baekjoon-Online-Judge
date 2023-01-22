#include <iostream>

using namespace std;

string str;

int main(void){
    cin >> str;

    int cnt = 1;
    for(int i = 0; i < str.size() - 1; i++){
        if(str[i] - 'a' < str[i + 1] - 'a') continue;
        else cnt++;
    }
    cout << cnt << '\n';
    return 0;
}