#include <iostream>
#include <algorithm>

using namespace std;

string str;
int arr[26];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i = 0; i < str.size(); i++) arr[str[i] - 'A']++;

    int mid_idx = -1, cnt = 0;
    for(int i = 0; i < 26; i++){
        if(arr[i] > 0 && arr[i] % 2 == 1){
            mid_idx = i;
            arr[i]--;
            cnt++;
        }
    }

    if(cnt >= 2) cout << "I'm Sorry Hansoo\n";
    else{
        string result = "", tmp = "";
        for(int i = 0; i < 26; i++){
            if(arr[i] > 0){
                for(int j = 0; j < arr[i] / 2; j++){
                    result += (i + 'A');
                }
            }
        }
        tmp = result;
        reverse(tmp.begin(), tmp.end());
        if(mid_idx != -1) result += (mid_idx + 'A');
        result += tmp;
        cout << result << '\n';
    }
    return 0;
}