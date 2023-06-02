#include <iostream>
#include <stack>

using namespace std;

long long result;
string str;
stack<char> s;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        char now = str[i];
        if(now == '(') s.push(now);
        else{
            if(s.top() == '(' && str[i - 1] == '('){
                s.pop();
                result += s.size();
            }
            else{
                s.pop();
                result++;
            }
        }
    }
    cout << result << '\n';
    return 0;
}