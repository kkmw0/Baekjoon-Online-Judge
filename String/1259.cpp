#include <iostream>

using namespace std;

string str;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        cin >> str;
        if(str == "0") break;

        int flag = 0;
        int left = 0;
        int right = str.size();
        while(left <= right){
            if(str[left] == str[right - 1]){
                left++;
                right--;
                continue;
            }
            else{
                flag = 1;
                break;
            }
        }
        if(flag) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }
    return 0;
}