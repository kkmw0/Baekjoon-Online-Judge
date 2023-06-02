#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string name;
int n, d, m, y;
vector<pair<int, string>> v;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name >> d >> m >> y;
        int s = y * 100 + m * 10 + d;
        v.push_back({s, name});
    }
    sort(v.begin(), v.end());
    cout << v[n - 1].second << '\n' << v[0].second << '\n';
    return 0;
}