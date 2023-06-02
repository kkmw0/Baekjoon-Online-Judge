#include <iostream>

using namespace std;

int t, n;

int main(void){
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        cin >> n;

        int s = 0;
        double d = 0;
        for(int i = 0; i < n; i++){
            double x, score;
            cin >> x >> score;
            s += x; d += (score * x);
        }
        cout << s << ' ';
        cout << fixed;
        cout.precision(1);
        cout << d / s << '\n';
    }
    return 0;
}