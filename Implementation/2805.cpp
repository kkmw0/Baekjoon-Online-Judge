#include <iostream>
#include <algorithm>

using namespace std;

long long result;
int n, m;
int arr[1000001];

bool check(long long height){
    long long s = 0;
    for(int i = 0; i < n; i++){
        long long value = arr[i] - height;
        if(value > 0) s += value;
    }
    if(s >= m){
        result = max(result, height);
        return true;
    }
    else return false;
}

void binary_search(long long start, long long end){
    while(start <= end){
        long long mid = start + (end - start) / 2;
        check(mid) ? start = mid + 1 : end = mid - 1;
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    binary_search(0, 2e9);
    cout << result << '\n';
    return 0;
}