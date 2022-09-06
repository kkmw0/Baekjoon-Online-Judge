#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, m;
string site, password;
vector<string> answer;
unordered_map<string, string> notepad;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> site >> password;
        notepad.insert({site, password});
    }

    for(int i = 0; i < m; i++){
        cin >> site;
        answer.push_back(notepad[site]);
    }

    int len = answer.size();
    for(int i = 0; i < len; i++){
        cout << answer[i] << '\n';
    }
    return 0;
}