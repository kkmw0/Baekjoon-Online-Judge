#include <iostream>

using namespace std;

int n, result;
int s1[26], s2[26];
string str1, str2;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str1 >> str2;
    for(int i = 0; i < str1.size(); i++) s1[str1[i] - 'a']++;
    for(int i = 0; i < str2.size(); i++) s2[str2[i] - 'a']++;

    for(int i = 0; i < 26; i++){
        if(s1[i] == s2[i]) continue;
        else if(s1[i] > s2[i]) result += s1[i] - s2[i];
        else result += s2[i] - s1[i];
    }
    cout << result << '\n';
    return 0;
}