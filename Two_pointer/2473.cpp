#include <iostream>
#include <algorithm>

using namespace std;

long long n, a, b, c;
long long arr[5001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    bool flag = false;
    long long result = 1e10;
    for(int i = 0; i < n - 2 && !flag; i++){
        long long pivot = i, left = pivot + 1, right = n - 1;
        while(left < right){
            long long tmp = arr[pivot] + arr[left] + arr[right];
            long long s = abs(tmp);
            if(s < result){
                a = arr[pivot];
                b = arr[left];
                c = arr[right];
                result = s;
            }

            if(tmp < 0) left++;
            else if(tmp == 0){
                flag = true;
                break;
            }
            else right--;
        }
    }
    cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}