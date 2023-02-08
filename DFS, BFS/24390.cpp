#include <iostream>
#include <queue>
#include <string>

using namespace std;

int t;
int value[4] = {10, 60, 600, 30};
bool visited[2][3601];
string timer;

int bfs(){
    queue<pair<pair<int, int>, bool>> q;
    q.push({{0, 0}, false});
    visited[0][0] = true;

    while(!q.empty()){
        int now_t = q.front().first.first;
        int cost = q.front().first.second;
        int is_on = q.front().second;
        q.pop();

        if(now_t == t && is_on) return cost;

        for(int i = 0; i < 4; i++){
            int nx = now_t + value[i];
            bool flag = is_on;
            if(i == 3 && !is_on){
                flag = true;
                if(now_t != 0) nx -= value[i];
            }
            if(!visited[flag][nx] && nx <= t){
                visited[flag][nx] = true;
                q.push({{nx, cost + 1}, flag});
            }
        }
    }
}

int main(void){
    cin >> timer;
    t = stoi(timer.substr(0, 2)) * 60 + stoi(timer.substr(3, 2));
    cout << bfs() << '\n';
    return 0;
}