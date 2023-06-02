#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string now, start, result;
int now_t, start_t, sub, h, m, s;

int main(void){
    cin >> now >> start;
    now_t = stoi(now.substr(0, 2)) * 3600 + stoi(now.substr(3, 2)) * 60 + stoi(now.substr(6, 2));
    start_t = stoi(start.substr(0, 2)) * 3600 + stoi(start.substr(3, 2)) * 60 + stoi(start.substr(6, 2));
    if(now_t > start_t) sub = 86400 - now_t + start_t;
    else sub = start_t - now_t;

    h = sub / 3600; m = sub % 3600 / 60; s = sub % 3600 % 60;
    
    result += h < 10 ? "0" + to_string(h) : to_string(h); result += ":";
    result += m < 10 ? "0" + to_string(m) : to_string(m); result += ":";
    result += s < 10 ? "0" + to_string(s) : to_string(s);
    cout << result << '\n';
    return 0;
}