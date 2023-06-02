#include <iostream>

using namespace std;

int n, k, result;
int arr[2][7];

int main(void){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int s, g;
        cin >> s >> g;
        arr[s][g]++;
    }
    for(int i = 1; i <= 6; i++){
        int f = arr[0][i];
        int m = arr[1][i];
        if(f != 0) result += (f / k == 0 ? 1 : f % k == 0 ? f / k : f / k + 1);
        if(m != 0 )result += (m / k == 0 ? 1 : m % k == 0 ? m / k : m / k + 1);
    }
    cout << result << '\n';
    return 0;
}