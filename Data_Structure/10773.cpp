#include <iostream>
#include <stack>

using namespace std;

int k;
stack<int> stk;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        if(x == 0){
            if(!stk.empty()) stk.pop();
        }
        else{
            stk.push(x);
        }
    }
    int result = 0;
    while(!stk.empty()){
        result += stk.top();
        stk.pop();
    }
    cout << result << '\n';
    return 0;
}