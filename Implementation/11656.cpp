#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string str;
vector<string> v;

int main(void){
    cin >> str;

    v.push_back(str);
    for(int i = 1; i < str.size(); i++){
        string tmp = str.substr(i, str.size() - i);
        if(tmp == "") break;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) cout << v[i] << '\n';
    return 0;
}