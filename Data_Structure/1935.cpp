#include <iostream>
#include <stack>

using namespace std;

int n;
double arr[26];
string str;
stack<double> st;

void solve(){
    for(int i = 0; i < str.size(); i++){
        char now = str[i];
        if(now >= 'A' && now <= 'Z') st.push(arr[now - 'A']);
        else{
            double a = st.top(); st.pop();
            double b = st.top(); st.pop();
            if(now == '+') st.push(b + a);
            else if(now == '-') st.push(b - a);
            else if(now == '*') st.push(b * a);
            else st.push(b / a);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << st.top() << '\n';
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> str;
    for(int i = 0; i < n; i++) cin >> arr[i];
    solve();
    return 0;
}