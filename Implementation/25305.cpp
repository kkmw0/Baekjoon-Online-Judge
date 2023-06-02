#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[1001];

bool cmp(int a, int b){
    return a > b;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, cmp);
    cout << arr[k - 1] << '\n';
    return 0;
}