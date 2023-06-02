#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
long long arr[1000001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        reverse(str.begin(), str.end());
        long long tmp = stoll(str);
        arr[i] = tmp;
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) cout << arr[i] << '\n';
    return 0;
}