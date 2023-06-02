#include <iostream>
#include <algorithm>

using namespace std;

int p, n;
int a[1000];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> p >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int result = 0;
    for(int i = 0; i < n; i++){
        int now = a[i];
        if(p < 200){
            result++;
            p += now;
        }
        else break;
    }
    cout << result << '\n';
    return 0;
}