#include <iostream>

using namespace std;

int n;
int arr[200001];
int d[200001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int min_value = arr[0]; d[0] = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i] > min_value) {
            if(d[i - 1] > arr[i] - min_value) d[i] = d[i - 1];
            else d[i] = arr[i] - min_value;
        }
        else {
            d[i] = d[i - 1];
            min_value = arr[i];
        }
    }
    for(int i = 0; i < n; i++) cout << d[i] << ' ';
    return 0;
}