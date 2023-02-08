#include <iostream>
#include <algorithm>

using namespace std;

int n, result;
int arr[200001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int max_value = -1;
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] > max_value) max_value = arr[i];
        result = max(result, max_value - arr[i]);
    }
    cout << result << '\n';
    return 0;
}