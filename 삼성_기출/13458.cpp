#include <iostream>

using namespace std;

long long result;
int n, b, c;
int arr[1000000];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> b >> c;

    for(int i = 0; i < n; i++){
        int now = arr[i] - b;
        result++;
        if(now <= 0) continue;
        else{
            int div = now / c;
            int e = now % c;
            if(e == 0) result += div;
            else result += div + 1;
        }
    }
    cout << result << '\n';
    return 0;
}