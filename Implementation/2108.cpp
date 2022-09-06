#include <bits/stdc++.h>

using namespace std;

int n, sum, maximum;
vector<int> v;
int arr[8001];

int main(){
    cin >> n;

    memset(arr, -1, sizeof(arr));
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
        arr[4000 + x]++;
        sum += x;
        maximum = max(maximum, arr[4000 + x]);
    }

    sort(v.begin(), v.end());

    int mode = 0;
    int flag = 0;
    for(int i = 0; i < 8001; i++){
        if(arr[i] == maximum){
            mode = i - 4000;
            if(flag) break;
            else flag = 1;
        }
    }

    int avg = round(sum / (double)n);
    cout << avg << '\n';
    cout << v[n / 2] << '\n';
    cout << mode << '\n';
    cout << v[n - 1] - v[0] << '\n';

    return 0;
}