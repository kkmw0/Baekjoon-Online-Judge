#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, result, last;
vector<pair<int, int>> v;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());

    result = last = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].second < last) continue;
        last = v[i].first;
        result++;
    }
    cout << result << '\n';
    return 0;
}