#include <iostream>
#include <stack>

using namespace std;

int n, result;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        stack<char> s;
        string str; cin >> str;

        for(int i = 0; i < str.size(); i++){
            char now = str[i];
            if(s.empty()) s.push(now);
            else{
                if(now == s.top()) s.pop();
                else s.push(now);
            }
        }
        if(s.empty()) result++;
    }
    cout << result << '\n';
    return 0;
}