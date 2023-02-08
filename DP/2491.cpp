#include <iostream>
#include <algorithm>

using namespace std;

int n, result = 1;
int arr[100001];
int d_inc[100001];
int d_dec[100001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        d_inc[i] = 1;
        d_dec[i] = 1;
    }

    for(int i = 2; i <= n; i++){
        if(arr[i] >= arr[i - 1]) d_inc[i] = d_inc[i - 1] + 1;
        if(d_inc[i] > result) result = d_inc[i];
    }
    for(int i = 1; i <= n; i++){
        if(arr[i] <= arr[i - 1]) d_dec[i] = d_dec[i - 1] + 1;
        if(d_dec[i] > result) result = d_dec[i];
    }
    cout << result << '\n';
    return 0;
}