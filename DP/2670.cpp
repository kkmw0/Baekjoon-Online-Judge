#include <iostream>

using namespace std;

int n;
double arr[10001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    double result = 0;
    for(int i = 1; i <= n; i++){
        double now = arr[i];
        if(now > result) result = now;
        for(int j = i + 1; j <= n; j++){
            now *= arr[j];
            if(now > result) result = now;
        }
    }
    cout << fixed;
    cout.precision(3);
    cout << result << '\n';
    return 0;
}