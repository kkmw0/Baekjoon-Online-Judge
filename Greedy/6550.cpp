#include <iostream>

using namespace std;

string s, t;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> s >> t){
        int idx = 0;
        bool flag = false;

        for(int i = 0; i < t.size(); i++){
            if(t[i] == s[idx]) idx++;
            if(idx == s.size()){
                flag = true;
                break;
            }
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}