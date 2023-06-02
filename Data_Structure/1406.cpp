#include <iostream>
#include <list>

using namespace std;

string str;
int m;
list<char> li;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str >> m;
    for(auto ch : str) li.push_back(ch);

    auto cursor = li.end();
    for(int i = 0; i < m; i++){
        char command;
        cin >> command;
        
        if(command == 'L'){
            if(cursor != li.begin()) cursor--;
        }
        else if(command == 'D'){
            if(cursor != li.end()) cursor++;
        }
        else if(command == 'B'){
            if(cursor != li.begin()){
                cursor--;
                cursor = li.erase(cursor);
            }
        }
        else{
            char ch;
            cin >> ch;
            li.insert(cursor, ch);
        }
    }
    for(auto ch : li) cout << ch;
    return 0;
}