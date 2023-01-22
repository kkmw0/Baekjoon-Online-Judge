#include <iostream>
#include <set>

using namespace std;

int m, x;
string str;
set<int> s;
set<int>::iterator it;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> str;
        if(!str.compare("add")){
            cin >> x;
            s.insert(x);
        }
        else if(!str.compare("remove")){
            cin >> x;
            s.erase(x);
        }
        else if(!str.compare("check")){
            cin >> x;
            it = s.find(x);
            if(it != s.end()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(!str.compare("toggle")){
            cin >> x;
            it = s.find(x);
            if(it != s.end()) s.erase(x);
            else s.insert(x);
        }
        else if(!str.compare("all")){
            for(int j = 1; j <= 20; j++) s.insert(j);
        }
        else s.clear();
    }
    return 0;
}