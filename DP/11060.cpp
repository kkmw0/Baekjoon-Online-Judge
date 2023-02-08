#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int n;
int arr[1001];
int d[1001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        d[i] = INF;
    }

    d[1] = 0;
    for(int i = 1; i <= n; i++){
        int now = arr[i];
        for(int j = i + 1; j <= i + now; j++){
            d[j] = min(d[j], d[i] + 1);
        }
    }
    if(d[n] >= INF) cout << -1 << '\n';
    else cout << d[n] << '\n';
    return 0;
}