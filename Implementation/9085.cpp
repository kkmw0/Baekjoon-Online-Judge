#include <iostream>

using namespace std;

int t, n;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        cin >> n;

        int result = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            result += x;
        }
        cout << result << '\n';
    }
    return 0;
}