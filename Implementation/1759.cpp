#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> word, pick;

void dfs(int idx, int cnt){
    if(cnt == l){
        int cons = 0, vow = 0;
        for(int i = 0; i < pick.size(); i++){
            char now = pick[i];
            if(now == 'a' || now == 'e' || now == 'i' || now == 'o' || now == 'u') vow++;
            else cons++;
        }
        if(cons >= 2 && vow >= 1){
            for(int i = 0; i < pick.size(); i++) cout << pick[i];
            cout << '\n';
        }
        return;
    }
    for(int i = idx; i < word.size(); i++){
        pick.push_back(word[i]);
        dfs(i + 1, cnt + 1);
        pick.pop_back();
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> l >> c;
    for(int i = 0; i < c; i++){
        char ch;
        cin >> ch;
        word.push_back(ch);
    }
    sort(word.begin(), word.end());

    dfs(0, 0);
    return 0;
}
