#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
int arr[500001];
stack<pair<int, int>> s;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> answer(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = n; i >= 1; i--){
        while(!s.empty()){
            pair<int, int> now = s.top();
            if(now.first >= arr[i]) break;
            answer[now.second] = i;
            s.pop();
        }
        s.push({arr[i], i});
    }
    for(int i = 1; i <= n; i++) cout << answer[i] << ' ';
    return 0;
}