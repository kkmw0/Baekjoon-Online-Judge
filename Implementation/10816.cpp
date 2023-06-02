#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[500000];

int find_lowerbound(int value){
    int start = 0, end = n;
    while(start < end){
        int mid = start + (end - start) / 2;
        if(arr[mid] < value) start = mid + 1;
        else end = mid;
    }
    return start;
}

int find_upperbound(int value){
    int start = 0, end = n;
    while(start < end){
        int mid = start + (end - start) / 2;
        if(arr[mid] <= value) start = mid + 1;
        else end = mid;
    }
    return start;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    cin >> m;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        int start = find_lowerbound(x);
        int end = find_upperbound(x);
        cout << end - start << ' ';
    }
    return 0;
}