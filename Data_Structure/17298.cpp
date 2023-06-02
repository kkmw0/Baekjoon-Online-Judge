#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
stack<pair<int, int>> s;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    vector<int> result(n, -1);
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        if(s.empty() || s.top().first >= num) s.push({num, i});
        else{
            while(true){
                int now = s.top().first;
                int idx = s.top().second;

                if(now >= num) break;
                else{
                    s.pop();
                    result[idx] = num;
                }
                if(s.empty()) break;
            }
            s.push({num, i});
        }
    }
    for(int i = 0; i < n; i++) cout << result[i] << ' ';
    return 0;
}