#include <iostream>

using namespace std;

int n;
int arr[100000];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int max_value = arr[n - 1];
    int cnt = 1;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] > max_value){
            cnt++;
            max_value = arr[i];
            continue;
        }
    }
    cout << cnt << '\n';
    return 0;
}