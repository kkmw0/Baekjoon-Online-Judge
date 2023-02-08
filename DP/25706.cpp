#include <iostream>

using namespace std;

int n;
int arr[200001];
int d[200001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    d[n] = 1;
    for(int i = n - 1; i >= 1; i--){
        int jump = arr[i] + 1;
        if(i + jump > n) d[i] = 1;
        else d[i] = d[i + jump] + 1;
    }
    for(int i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}