#include <iostream>
#include <algorithm>

using namespace std;

int n, result, *d;

int main(void){
    cin >> n;
    d = new int[n + 1];
    fill_n(d, n + 1, 50001);

    d[2] = 1;
    d[5] = 1;
    for(int i = 3; i <= n; i++){
        if(i - 2 > 0 && d[i - 2] < 50001) d[i] = min(d[i - 2] + 1, d[i]);
        if(i - 5 > 0 && d[i - 5] < 50001) d[i] = min(d[i - 5] + 1, d[i]);
    }
    cout << (d[n] < 50001 ? d[n] : -1) << '\n';
    delete d;
    return 0;
}