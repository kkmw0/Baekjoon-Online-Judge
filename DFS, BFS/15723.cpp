#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m, flag;
bool visited[26];
vector<int> graph[26];

void init(){
    fill_n(visited, 26, false);
    flag = 0;   
}

void dfs(int x, int target){
    if(x == target) {
        flag = 1;
        return;
    }
    visited[x] = true;
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        if(!visited[now]) dfs(now, target);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string a;
        getline(cin, a);
        graph[a[0] - 'a'].push_back(a[a.size() - 1] - 'a');
    }
    cin >> m;
    cin.ignore();
    for(int i = 0; i < m; i++){
        init();

        string a;
        getline(cin, a);
        dfs(a[0] - 'a', a[a.size() - 1] - 'a');
        if(flag) cout << 'T' << '\n';
        else cout << 'F' << '\n';
    }
    return 0;
}