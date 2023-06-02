#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1001], d[1001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        d[i] = 1;
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j >= 0; j--){
            if(arr[i] > arr[j]) d[i] = max(d[i], d[j] + 1);
        }
        result = max(result, d[i]);
    }
    cout << result << '\n';
    return 0;
}