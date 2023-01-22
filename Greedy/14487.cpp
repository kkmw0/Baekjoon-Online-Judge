#include <iostream>

using namespace std;

int n;

int main(void){
    cin >> n;

    int sum = 0;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        sum += x;
        mx = x > mx ? x : mx;
    }
    cout << sum - mx << '\n';
}