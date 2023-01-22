#include <iostream>
#include <vector>
#include <algorithm>

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

    int result = 0;
    for(int i = 0; i < n; i++){
        if(result < v[i] * (n - i)){
            result = v[i] * (n - i);
        }
    }
    cout << result << '\n';
    return 0;
}