#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> stk;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        if(str == "push"){
            int x; cin >> x;
            stk.push(x);
        }
        else if(str == "pop"){
            if(stk.size() != 0){
                int x = stk.top();
                stk.pop();
                cout << x << '\n';
            }
            else cout << -1 << '\n';
        }
        else if(str == "size") cout << stk.size() << '\n';
        else if(str == "empty") cout << stk.empty() << '\n';
        else{
            if(stk.size() != 0) cout << stk.top() << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}