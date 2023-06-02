#include <iostream>
#include <algorithm>

using namespace std;

int n, x, result;
int arr[100000];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    sort(arr, arr + n);
    
    int p1 = 0, p2 = n - 1;
    while(true){
        if(p1 >= p2) break;
        
        int s = arr[p1] + arr[p2];
        if(s == x){
            p1++;
            p2--;
            result++;
        }
        else if(s > x) p2--;
        else p1++;
    }
    cout << result << '\n';
    return 0;
}