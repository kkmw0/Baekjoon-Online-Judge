#include <iostream>
#include <set>

using namespace std;

int n;
string str;

struct compare{
    bool operator() (const string &a, const string &b) const{
        if(a.size() == b.size()) return a < b;
        else return a.size() < b.size();
    }
};

int main(void){
    cin >> n;
    set<string, compare> s;
    for(int i = 0; i < n; i++){
        cin >> str;
        s.insert(str);
    }
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << '\n';
    }
    return 0;
}