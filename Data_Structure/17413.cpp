#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> st;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    getline(cin, str);

    bool flag = false;
    for(int i = 0; i < str.size(); i++){
        char now = str[i];

        if(now == '<'){
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            cout << '<';
            flag = true;
            continue;
        }
        
        if(now == '>'){
            cout << '>';
            flag = false;
            continue;
        }

        if(now == ' ' && !flag){
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            cout << ' ';
            continue;
        }

        if(flag) cout << now;
        else st.push(now);
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}