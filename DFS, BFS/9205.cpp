#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n, s_x, s_y, e_x, e_y;
bool visited[100];
vector<pair<int, int>> store;

void init(){
    store.clear();
    for(int i = 0; i < 100; i++){
        visited[i] = false;
    }
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});

    bool flag = false;
    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        int dist_e = abs(e_x - now_x) + abs(e_y - now_y);
        if(dist_e <= 1000){
            flag = true;
            break;
        }

        for(int i = 0; i < store.size(); i++){
            int dist_s = abs(store[i].first - now_x) + abs(store[i].second - now_y);
            if(dist_s <= 1000 && !visited[i]){
                visited[i] = true;
                q.push({store[i].first, store[i].second});
            }
        }
    }
    if(flag) cout << "happy\n";
    else cout << "sad\n";
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        cin >> n;
        cin >> s_x >> s_y;

        init();
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            store.push_back({x, y});
        }
        cin >> e_x >> e_y;
        bfs(s_x, s_y);
    }
    return 0;
}