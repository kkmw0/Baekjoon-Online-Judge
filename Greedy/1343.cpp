#include <iostream>

using namespace std;

bool flag = 0;
string str, result;

int main(void){
    cin >> str;
    for(int i = 0, idx = 0; i < str.size(); i += idx){
        idx = 0;
        if(str[i] == 'X'){
            int cnt = 0;
            for(int j = i; str[j] != '.' && str[j] != '\0'; j++) cnt++;
            if(cnt % 2 == 1){
                flag = 1;
                break;
            }
            else{
                for(int j = 0; j < cnt / 4; j++) result += "AAAA";
                for(int j = 0; j < cnt % 4; j++) result += 'B';
            }
            idx += cnt;
        }
        else{
            for(int j = i; str[j] != 'X' && str[j] != '\0'; j++){
                result += '.';
                idx++;
            }
        }
    }
    if(flag) cout << -1 << '\n';
    else cout << result << '\n';
    return 0;
}