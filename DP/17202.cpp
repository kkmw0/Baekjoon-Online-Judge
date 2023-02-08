#include <iostream>
#include <string>

using namespace std;

string str1, str2, mix;
int d[16];

int main(void){
    cin >> str1 >> str2;
    for(int i = 0; i < str1.size(); i++){
        mix += str1[i];
        mix += str2[i];
    }
    int len = mix.size();
    for(int i = 0; i < len; i++) d[i] = mix[i] - '0';
    for(int i = 0; i < len - 2; i++){
        for(int j = 0; j < len - i; j++){
            d[j] = (d[j] + d[j + 1]) % 10;
        }
    }
    string result = to_string(d[0]) + to_string(d[1]);
    cout << result << '\n';
    return 0;
}