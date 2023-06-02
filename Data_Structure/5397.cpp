#include <iostream>
#include <list>

using namespace std;

int t;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        list<char> li;
        string str; cin >> str;

        auto cursor = li.begin();
        for(auto ch : str){
            if(ch == '<'){
                if(cursor != li.begin()) cursor--;
            }
            else if(ch == '>'){
                if(cursor != li.end()) cursor++;
            }
            else if(ch == '-'){
                if(cursor != li.begin()){
                    cursor--;
                    cursor = li.erase(cursor);
                }
            }
            else{
                li.insert(cursor, ch);
            }
        }
        for(auto ch : li) cout << ch;
        cout << '\n';
    }
    return 0;
}