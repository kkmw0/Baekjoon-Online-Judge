#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m, result;
vector<int> a, b;

void init(){
    a.clear(); b.clear();
    result = 0;
}

void input(){
    int x;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        b.push_back(x);
    }    
}

int binary_search(int value){
    int start = 0, end = m - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(value > b[mid]) start = mid + 1;
        else end = mid - 1;
    }
    return start;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        init();
        input();
        sort(b.begin(), b.end());

        for(int i = 0; i < n; i++){
            int now = a[i];
            result += binary_search(a[i]);
        }
        cout << result << '\n';
    }
    return 0;
}