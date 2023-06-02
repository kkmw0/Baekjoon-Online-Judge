#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, p;
vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b){
    return a.first > b.first;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        cin >> p;
        for(int i = 0; i < p; i++){
            int x;
            string str;
            cin >> x >> str;
            v.push_back({x, str});
        }
        sort(v.begin(), v.end(), cmp);
        cout << v[0].second << '\n';
        v.clear();
    }
    return 0;
}