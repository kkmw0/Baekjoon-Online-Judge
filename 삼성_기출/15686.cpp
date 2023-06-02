#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, result = 1e9;
int graph[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> pos;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 1) home.push_back({i, j});
            else if(graph[i][j] == 2) chicken.push_back({i, j});
        }
    }
    int len = chicken.size();
    vector<int> v(m, 1);
    for(int i = 0; i < len - m; i++) v.push_back(0);
    do{
        pos.clear();
        for(int i = 0; i < len; i++){
            if(v[i] == 1) pos.push_back({chicken[i].first, chicken[i].second});
        }

        int s = 0;
        for(int i = 0; i < home.size(); i++){
            int home_x = home[i].first;
            int home_y = home[i].second;
            int tmp = 1e9;
            for(int j = 0; j < pos.size(); j++){
                int now_x = pos[j].first;
                int now_y = pos[j].second;
                int d = abs(home_x - now_x) + abs(home_y - now_y);
                tmp = min(tmp, d);
            }
            s += tmp;
        }
        result = min(result, s);
    }while(prev_permutation(v.begin(), v.end()));
    cout << result << '\n';
    return 0;
}