#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int c;

int bfs(int start, int target){
    queue<pair<int, pair<int, int>>> q;
    q.push({start, {target, 0}});

    while(!q.empty()){
        int now = q.front().first;
        int target = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if(now > target) continue;
        if(now == target) return cost;

        q.push({now << 1, {target + 3, cost + 1}});
        q.push({now + 1, {target, cost + 1}});
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c;
    for(int i = 0; i < c; i++){
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) << '\n';
    }
    return 0;
}