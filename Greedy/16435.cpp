#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector<int> v;

int main(void){
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        if(v[i] > l) break;
        else l++;
    }
    cout << l << '\n';
    return 0;
}