#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, l, result = 1;
vector<int> v;

int main(void){
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int now = v[0];
    for(int i = 1; i < n; i++){
        if(now + l > v[i]) continue;
        else{
            now = v[i];
            result++;
        }
    }
    cout << result << '\n';
    return 0;
}