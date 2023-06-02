#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long result;
int n;
stack<int> stk;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int height; cin >> height;
        if(stk.empty() || stk.top() > height) stk.push(height);
        else{
            while(true){
                int now = stk.top();
                if(now > height) break;
                else{
                    stk.pop();
                    if(stk.empty()) break;
                    result += stk.size();
                }
            }
            stk.push(height);
        }
    }
    while(true){
        if(stk.empty()) break;
        stk.pop();
        result += stk.size();
    }
    cout << result << '\n';
    return 0;
}