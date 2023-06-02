#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int t, a, b, D, S, L, R;
pair<int, char> path[10000];
vector<char> result;

void init(){
    result.clear();
    for(int i = a; i <= b; i++){
        path[i].first = 0;
        path[i].second = ' ';
    }
}

int bfs(int a){
    bool visited[10000] = {false, };
    queue<pair<int, int>> q;
    q.push({a, 0});
    visited[a] = true;
    path[a] = {0, ' '};

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(now == b) return cost;

        //D
        D = (now * 2) % 10000;
        if(!visited[D]){
            path[D] = {now, 'D'};
            visited[D] = true;
            q.push({D, cost + 1});
        }

        //S
        S = now - 1 < 0 ? 9999 : now - 1;
        if(!visited[S]){
            path[S] = {now, 'S'};
            visited[S] = true;
            q.push({S, cost + 1});
        }

        //L
        L = (now % 1000) * 10 + (now / 1000);
        if(!visited[L]){
            path[L] = {now, 'L'};
            visited[L] = true;
            q.push({L, cost + 1});
        }

        //R
        R = now / 10 + (now % 10) * 1000;
        if(!visited[R]){
            path[R] = {now, 'R'};
            visited[R] = true;
            q.push({R, cost + 1});
        }
    }
}

void solve(){
    init();
    int cnt = bfs(a);

    int idx = b;
    while(cnt--){
        result.push_back(path[idx].second);
        idx = path[idx].first;
    }

    reverse(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++){
        cout << result[i];
    }
    cout << '\n';
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        cin >> a >> b;
        solve();
    }
    return 0;
}