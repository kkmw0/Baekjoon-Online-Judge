#include <iostream>
#include <algorithm>

using namespace std;

int avg, mid;
int arr[5];

int main(void){
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
        avg += arr[i];
    }
    sort(arr, arr + 5);
    cout << avg / 5 << '\n' << arr[2] << '\n';
    return 0;
}