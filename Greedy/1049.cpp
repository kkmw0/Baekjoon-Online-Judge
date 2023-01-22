#include <iostream>
#include <algorithm>

using namespace std;

int n, m, package, single, result;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    package = single = 1001;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if(x < package) package = x;
        if(y < single) single = y;
    }
    cout << min({n / 6 * package + package, n * single, n / 6 * package + n % 6 * single}) << '\n';
    return 0;
}