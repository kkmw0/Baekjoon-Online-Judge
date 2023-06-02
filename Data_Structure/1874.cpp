#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, arr[100001];
stack<int> stk;
vector<char> result;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int idx = 0;
    for(int i = 1; i <= n; ){
        if(!stk.empty() && arr[idx] == stk.top()){
            idx++;
            stk.pop();
            result.push_back('-');
            continue;
        }
        else {
            stk.push(i);
            result.push_back('+');
            i++;
        }
    }

    bool flag = false;
    for(int i = idx; i < n; i++){
        if(!stk.empty() && arr[i] == stk.top()){
            stk.pop();
            result.push_back('-');
        }
        else{
            flag = true;
            break;
        }
    }
    if(!flag) for(auto ch : result) cout << ch << '\n';
    else cout << "NO\n";
    return 0;
}