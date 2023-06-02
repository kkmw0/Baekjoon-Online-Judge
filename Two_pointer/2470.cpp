#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[100001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    long long result = 1e10;
    int l = 0, r = n - 1, x, y;
    while(l < r){
        long long tmp = arr[l] + arr[r];
        long long s = abs(tmp);
        if(s < result){
            x = arr[l];
            y = arr[r];
            result = s;
        }

        if(tmp < 0) l++;
        else if(tmp == 0) break;
        else r--;
    }
    cout << x << ' ' << y << '\n';
    return 0;
}