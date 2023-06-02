#include <iostream>

using namespace std;

int n;
int arr[1001];
int d[1001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        d[i] = arr[i];
    }

    int result = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j]) d[i] = max(d[i], d[j] + arr[i]);
        }
        result = max(result, d[i]);
    }
    cout << result << '\n';
    return 0;
}