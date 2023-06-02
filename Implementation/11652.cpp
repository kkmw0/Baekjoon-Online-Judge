#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int n;
map<ll, ll> m;
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        if(m[x] == 0) m[x] = 1;
        else m[x]++;
    }
    for(auto it = m.begin(); it != m.end(); it++){
        v.push_back({it->second, it->first});
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].second << '\n';
    return 0;
}