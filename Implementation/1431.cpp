#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<string> str;

bool cmp(string str1, string str2){
    int len1 = str1.size();
    int len2 = str2.size();

    if(len1 == len2){
        int s1 = 0, s2 = 0;
        for(int i = 0; i < len1; i++){
            if(str1[i] >= '0' && str1[i] <= '9') s1 += (str1[i] - '0');
        }
        for(int i = 0; i < len2; i++){
            if(str2[i] >= '0' && str2[i] <= '9') s2 += (str2[i] - '0');
        }
        if(s1 == s2) return str1 < str2;
        else return s1 < s2;
    }
    else return len1 < len2;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        str.push_back(s);
    }
    sort(str.begin(), str.end(), cmp);
    for(int i = 0; i < str.size(); i++) cout << str[i] << '\n';
    return 0;
}