#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt, result;
int value[10001];
bool visited[10001];
vector<int> graph[10001];

void init(){
    cnt = 0;
    for(int i = 1; i <= n; i++){
        visited[i] = false;
    }
}

void dfs(int x){
    visited[x] = true;
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        if(!visited[now]){
            cnt++;
            dfs(now);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        init();
        dfs(i);
        if(cnt > result) result = cnt;
        value[i] = cnt;
    }
    for(int i = 1; i <= n; i++){
        if(value[i] == result) cout << i << ' ';
    }
    return 0;
}