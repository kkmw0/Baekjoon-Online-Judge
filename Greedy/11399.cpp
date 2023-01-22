#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    long long sum = 0;
    int len = v.size();
    for(int i = 0; i < len; i++){
        for(int j = 0; j <= i; j++){
            sum += v[j];
        }
    }
    cout << sum << '\n';
    return 0;
}