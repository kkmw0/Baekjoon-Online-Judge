#include <iostream>

using namespace std;

int t, s, n;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        cin >> s >> n;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            s += (y * x);
        }
        cout << s << '\n';
    }
    return 0;
}