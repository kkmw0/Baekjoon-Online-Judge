#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, result;
vector<int> v;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x + 1);
    }
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i = 0; i < v.size(); i++){
        int now = i + v[i] + 1;
        if(now > result) result = now;
    }
    cout << result << '\n';
    return 0;
}