#include <iostream>

using namespace std;

int n, s, r;
int condi[12], broken[12], addi[12];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s >> r;
    for(int i = 1; i <= n; i++) condi[i] = 1;
    for(int i = 1; i <= s; i++){
        cin >> broken[i];
        condi[broken[i]]--;
    }
    for(int i = 1; i <= r; i++){
        cin >> addi[i];
        condi[addi[i]]++;
    }

    int result = 0;
    for(int i = 1; i <= n; i++){
        int now = condi[i];
        if(now == 0){
            if(condi[i - 1] <= 1 && condi[i + 1] <= 1){
                result++;
                continue;
            }
            if(condi[i - 1] >= 2) condi[i - 1]--;
            else if(condi[i + 1] >= 2) condi[i + 1]--;
            condi[i]++;
        }
    }
    cout << result << '\n';
    return 0;
}