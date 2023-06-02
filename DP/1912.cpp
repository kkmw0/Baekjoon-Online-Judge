#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int d[100000];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        d[i] = arr[i];
    }

    int result = d[0];
    for(int i = 1; i < n; i++){
        d[i] = max(d[i], d[i - 1] + arr[i]);
        if(d[i] > result) result = d[i];
    }
    cout << result << '\n';
    return 0;
}