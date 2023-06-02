#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m;
string str;
map<string, int> name_dict;
map<int, string> num_dict;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> str;
        name_dict[str] = i;
        num_dict[i] = str;
    }

    for(int i = 0; i < m; i++){
        cin >> str;
        if(str[0] >= '0' && str[0] <= '9') cout << num_dict[stoi(str)] << '\n';
        else cout << name_dict[str] << '\n';
    }
    return 0;
}