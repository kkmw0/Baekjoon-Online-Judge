#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<int> value;
vector<char> oper;

int main(void){
    cin >> str;

    string tmp = "";
    for(int i = 0; i < str.size(); i++){
        if(str[i] != '+' && str[i] != '-') tmp += str[i];
        else{
            value.push_back(stoi(tmp));
            oper.push_back(str[i]);
            tmp = "";
        }
    }
    value.push_back(stoi(tmp));

    int flag = 0;
    int temp = 0;
    int sum = value[0];
    for(int i = 0, j = 1; i < value.size() - 1; i++, j++){
        if(oper[i] == '-'){
            if(flag == 0){
                temp += value[j];
                flag = 1;
            }
            else sum -= value[j];
        }
        else{
            if(flag == 1) temp += value[j];
            else sum += value[j];
        }
    }
    cout << sum + (temp * -1) << '\n';
    return 0;
}