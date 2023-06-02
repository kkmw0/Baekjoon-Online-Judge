#include <iostream>
#include <algorithm>

using namespace std;

long long n, stick, result;
long long arr[500000];

bool cmp(long long a, long long b){
    return a > b;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        stick += arr[i];
    }
    sort(arr, arr + n, cmp);

    for(int i = 0; i < n; i++){
        long long value = stick - arr[i];
        result += (value * arr[i]);
        stick = value;
    }
    cout << result << '\n';
    return 0;
}