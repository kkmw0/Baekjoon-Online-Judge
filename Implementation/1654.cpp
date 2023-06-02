#include <iostream>

using namespace std;

int k, n;
long long arr[10001];

bool check(long long x){
    long long s = 0;
    for(int i = 0; i < k; i++){
        s += (arr[i] / x);
    }
    if(s >= n) return true;
    else return false;
}

long long binary_search(long long start, long long end){
    while(start != end){
        long long mid = start + (end - start + 1) / 2;
        check(mid) ? start = mid : end = mid - 1; 
    }
    return start;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k >> n;
    for(int i = 0; i < k; i++) cin >> arr[i];
    cout << binary_search(0, 1e18) << '\n';
    return 0;
}