#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, result;
vector<int> v;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    v.push_back(-INF);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(v.back() < x){
            v.push_back(x);
            result++;
        }
        else{
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }
    cout << result << '\n';
    return 0;
}