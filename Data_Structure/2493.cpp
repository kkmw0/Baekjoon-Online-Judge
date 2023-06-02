#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, arr[500000];
stack<pair<int, int>> stk;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> result(n, 0);
    for(int i = n - 1; i >= 0; i--){
        while(!stk.empty()){
            int idx = stk.top().first;
            int height = stk.top().second;

            if(arr[i] <= height) break;
            result[idx] = i + 1;
            stk.pop();
        }
        stk.push({i, arr[i]});
    }
    for(int i = 0; i < n; i++) cout << result[i] << ' ';
    return 0;
}