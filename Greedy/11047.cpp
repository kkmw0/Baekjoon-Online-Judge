#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> v;

int main(void){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    int len = v.size() - 1;
    int sum = 0;
    for(int i = len; i >= 0; i--){
        sum += k / v[i];
        k %= v[i];
    }
    cout << sum << '\n';
    return 0;
}