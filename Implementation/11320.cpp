#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string str1, str2;
        cin >> str1 >> str2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if(str1 == str2) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';
    }
    return 0;
}