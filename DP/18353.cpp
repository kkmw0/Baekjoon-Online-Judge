#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[2001], d[2001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        d[i] = 1;
    }

    int result = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--){
            if(arr[j] > arr[i]) d[i] = max(d[i], d[j] + 1);
        }
        result = max(result, d[i]);
    }
    cout << n - result << '\n';
    return 0;
}