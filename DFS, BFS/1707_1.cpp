#include <iostream>
#include <vector>
#define WHITE 1
#define BLACK 2

using namespace std;

int k, v, e;
int visited[20001];
vector<int> graph[20001];

void init(){
    for(int i = 1; i <= v; i++){
        visited[i] = 0;
        graph[i].clear();
    }
}

void dfs(int x){
    if(!visited[x]) visited[x] = WHITE;
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        if(!visited[now]){
            if(visited[x] == WHITE) visited[now] = BLACK;
            else if(visited[x] == BLACK) visited[now] = WHITE;
            dfs(now);
        }
    }
}

bool check(){
    for(int i = 1; i <= v; i++){
        for(int j = 0; j < graph[i].size(); j++){
            int now = graph[i][j];
            if(visited[i] == visited[now]) return false;
        }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k;
    for(int test_case = 0; test_case < k; test_case++){
        cin >> v >> e;

        init();
        for(int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i = 1; i <= v; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        if(check()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}