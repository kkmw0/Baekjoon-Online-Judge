#include <iostream>
#include <queue>

using namespace std;

struct Emo{
    int now, cost, clip;
};

int target;
bool visited[2001][2001];

int bfs(int start){
    queue<Emo> q;
    q.push({start, 0, 0});
    visited[start][0] = true;

    while(!q.empty()){
        int now = q.front().now;
        int cost = q.front().cost;
        int clip = q.front().clip;
        q.pop();

        if(now == target) return cost;

        int nclip = now;
        if(!visited[now][nclip]){
            visited[now][nclip] = true;
            q.push({now, cost + 1, nclip});
        }

        if(now + clip <= target && !visited[now + clip][clip]){
            visited[now + clip][clip] = true;
            q.push({now + clip, cost + 1, clip});
        }

        if(now - 1 >= 0 && !visited[now - 1][clip]){
            visited[now - 1][clip] = true;
            q.push({now - 1, cost + 1, clip});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> target;
    cout << bfs(1) << '\n';
    return 0;
}