#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;
string str;
vector<string> v;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    cin.ignore();
    for(int test_case = 1; test_case <= t; test_case++){
        v.clear();
        getline(cin, str);

        string tmp = "";
        for(int i = 0; i < str.size(); i++){
            char ch = str[i];
            if(ch == ' '){
                v.push_back(tmp);
                tmp = "";
            }
            else tmp += ch;       
        }
        v.push_back(tmp);
        cout << "Case #" << test_case << ": ";
        for(int i = v.size() - 1; i >= 0; i--){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}