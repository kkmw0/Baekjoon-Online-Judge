#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), compare);

    int cost = 0;
    for(int i = 0; i < m - 1; i++){
        if(v[i].first >= n) continue;
        else{
            cost += (n - v[i].first);
        }
    }
    cout << cost << '\n';
    return 0;
}