#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> s;

void init(){
    while(!s.empty()) s.pop();
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        getline(cin, str);
        if(str == ".") break;

        init();
        bool flag = false;
        for(int i = 0; i < str.size(); i++){
            char now = str[i];
            if(now == '(' || now == '[' || now == '{') s.push(now);
            else if(now == ')'){
                if(s.empty() || s.top() != '('){
                    flag = true;
                    break;
                }
                if(s.top() == '(') s.pop();
            }
            else if(now == ']'){
                if(s.empty() || s.top() != '['){
                    flag = true;
                    break;
                }
                if(s.top() == '[') s.pop();
            }
            else if(now == '}'){
                if(s.empty() || s.top() != '{'){
                    flag = true;
                    break;
                }
                if(s.top() == '{') s.pop();
            }
        }
        if(!s.empty()) flag = true;

        if(flag) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}