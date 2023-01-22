#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, n, res1, res2;
string sang;
vector<string> f;

bool is_win(char a, char b){
    if(a == 'S'){
        if(b == 'P') return true;
        else return false;
    }
    else if(a == 'R'){
        if(b == 'S') return true;
        else return false;
    }
    else{
        if(b == 'R') return true;
        else return false;
    }
}

int main(void){
    cin >> r >> sang >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        f.push_back(str);
    }
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < n; j++){
            if(sang[i] == f[j][i]) res1++;
            else{
                if(is_win(sang[i], f[j][i])) res1 += 2;
                else continue;
            }
        }
        int S = 0, R = 0, P = 0;
        for(int j = 0; j < n; j++){
            if(f[j][i] == 'S') S++;
            else if(f[j][i] == 'R') R++;
            else P++;
        }
        res2 += max({S * 2 + R, R * 2 + P, P * 2 + S});
    }
    cout << res1 << '\n' << res2 << '\n';
    return 0;
}