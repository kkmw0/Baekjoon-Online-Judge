#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> v;

bool Palindrome(string str){
    int len = str.size();
    for(int i = 0; i < len; i++){
        if(str[i] == str[len - i - 1]) continue;
        else return false;
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    int len = v.size();
    for(int i = 0; i < len; i++){
        int _size = v[i].size();
        if(Palindrome(v[i])){
            cout << _size << ' ' << v[i][_size / 2] << '\n';
            return 0;
        }
        reverse(v[i].begin(), v[i].end());
        for(int j = i + 1; j < len; j++){
            if(v[i] == v[j]){
                cout << _size << ' ' << v[i][_size / 2] << '\n';
                return 0;                
            }
        }
    }
}