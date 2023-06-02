#include <iostream>
#include <stack>

using namespace std;

int result;
string str;
stack<char> s;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;
    
    int tmp = 1;
    bool flag = false;
    for(int i = 0; i < str.size(); i++){
        char now = str[i];
        if(now == '('){
            s.push(now);
            tmp *= 2;
        }
        else if(now == '['){
            s.push(now);
            tmp *= 3;
        }
        else if(now == ')'){
            if(s.empty() || s.top() != '('){
                flag = true;
                break;
            }
            if(str[i - 1] == '(') result += tmp;
            s.pop();
            tmp /= 2;
        }
        else if(now == ']'){
            if(s.empty() || s.top() != '['){
                flag = true;
                break;
            }
            if(str[i - 1] == '[') result += tmp;
            s.pop();
            tmp /= 3;
        }
    }
    if(flag || !s.empty()) cout << 0 << '\n';
    else cout << result << '\n';
    return 0;
}