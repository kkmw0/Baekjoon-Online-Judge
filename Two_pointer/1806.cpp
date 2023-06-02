#include <iostream>

using namespace std;

int n, s;
int arr[100001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    int j = 0, value = 0, result = 2e9;
    for(int i = 1; i <= n; i++){
        while(j + 1 <= n && value < s){
            value += arr[j + 1];
            j++;
        }

        if(value < s) break;

        result = min(result, j - i + 1);
        value -= arr[i];
    }
    if(result == 2e9) cout << 0 << '\n';
    else cout << result << '\n';
    return 0;
}