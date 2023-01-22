#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t, n;
vector<pair<int, int>> v;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for(int test_case = 1; test_case <= t; test_case++){
        int result = 1;
        v.clear();

        cin >> n;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end());

        int score = v[0].second;
        for(int i = 1; i < v.size(); i++){
            int now = v[i].second;
            if(now < score){
                result++;
                score = now;
            }
            else continue;
        }
        cout << result << '\n';
    }
    return 0;
}