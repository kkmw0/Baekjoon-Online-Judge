#include <iostream>
#include <algorithm>

using namespace std;

int n, result;
int arr[100001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int pivot = 2e9 + 1;
    int start = 0, end = n - 1;
    while(start < end){
        int tmp = arr[start] + arr[end];
        int s = abs(tmp);

        if(s < pivot){
            if(tmp < 0) result = -s;
            else result = s;
            pivot = s;
        }

        if(tmp < 0) start++;
        else if(tmp == 0) break;
        else end--;
    }
    cout << result << '\n';
    return 0;
}