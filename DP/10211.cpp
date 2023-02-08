#include <iostream>

using namespace std;

int t, n;
int arr[1001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];

        int max_value = -1e9;
        for(int i = 0; i < n; i++){
            int now = arr[i];
            if(now > max_value) max_value = now;
            for(int j = i + 1; j < n; j++){
                now += arr[j];
                if(now > max_value) max_value = now;
            }
        }
        cout << max_value << '\n';
    }
    return 0;
}