#include <iostream>

using namespace std;

int t;
int ans[3];
int arr[3] = {300, 60, 10};

int main(void){
    cin >> t;
    if(t % 10 != 0) cout << -1 << '\n';
    else{
        for(int i = 0; i < 3; i++){
            if(t / arr[i]){
                ans[i] = t / arr[i];
                t %= arr[i];
            }
        }
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    }
    return 0;
}