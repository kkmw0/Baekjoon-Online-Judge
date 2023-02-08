#include <iostream>
#include <vector>

using namespace std;

int n, k, result;
int apple[100000];
vector<int> graph[100000];

void dfs(int x, int cnt){
    if(cnt > k) return;
    result += apple[x];
    for(int i = 0; i < graph[x].size(); i++){
        int now = graph[x][i];
        dfs(now, cnt + 1);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 0; i < n; i++) cin >> apple[i];

    dfs(0, 0);
    cout << result << '\n';
    return 0;
}