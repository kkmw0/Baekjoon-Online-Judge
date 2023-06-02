#include <iostream>
#include <deque>

using namespace std;

string str;
int n, x;
deque<int> dq;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str == "push_front"){
            cin >> x;
            dq.push_front(x);
        }
        else if(str == "push_back"){
            cin >> x;
            dq.push_back(x);
        }
        else if(str == "pop_front"){
            if(dq.size() == 0) cout << -1 << '\n';
            else {
                int now = dq.front();
                cout << now << '\n';
                dq.pop_front();
            }
        }
        else if(str == "pop_back"){
            if(dq.size() == 0) cout << -1 << '\n';
            else {
                int now = dq.back();
                cout << now << '\n';
                dq.pop_back();
            }
        }
        else if(str == "size") cout << dq.size() << '\n';
        else if(str == "empty") cout << dq.empty() << '\n';
        else if(str == "front"){
            if(dq.size() == 0) cout << -1 << '\n';
            else{
                int now = dq.front();
                cout << now << '\n';
            }
        }
        else if(str == "back"){
            if(dq.size() == 0) cout << -1 << '\n';
            else{
                int now = dq.back();
                cout << now << '\n';
            }
        }
    }
    return 0;
}