#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];

bool cmp(int a, int b){
    return a > b;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, cmp);

    int idx = 0, result = 0;
    for(int i = 0; i < n / 3; i++){
        result += arr[idx] + arr[idx + 1];
        idx += 3;
    }
    for(int i = idx; i < n; i++) result += arr[i];
    cout << result << '\n';
    return 0;
}