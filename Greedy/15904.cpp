#include <iostream>
#include <string>

using namespace std;

bool flag = false;
string str, text = "UCPC";

int main(void){
    getline(cin, str);

    int idx = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == text[idx]){
            idx += 1;
            if(idx == 4){
                flag = true;
                break;
            }
        }
    }
    if(flag) cout << "I love UCPC" << '\n';
    else cout << "I hate UCPC" << '\n';
    return 0;
}