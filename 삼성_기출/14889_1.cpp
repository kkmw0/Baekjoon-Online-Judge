#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, result = 1e9;
int arr[20][20];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> v(n / 2, 1);
    for(int i = 0; i < n - n / 2; i++) v.push_back(0);
    do{
        int team_s[2] = {0, 0};
        for(int i = 0; i < v.size(); i++){
            int now_team = v[i];
            for(int j = 0; j < v.size(); j++){
                if(j == i) continue;
                if(now_team == v[j]) team_s[now_team] += arr[i][j];
            }
        }

        int value = abs(team_s[0] - team_s[1]);
        result = min(result, value);
    }while(prev_permutation(v.begin(), v.end()));
    cout << result << '\n';
    return 0;
}