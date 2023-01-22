#include <iostream>

using namespace std;

int n, result;
int arr[101];

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = n - 1; i >= 1; i--){
        if(arr[i] > arr[i - 1]) continue;
        else{
            result += arr[i - 1] - arr[i] + 1;
            arr[i - 1] = arr[i] - 1;
        }
    }
    cout << result << '\n';
    return 0;
}