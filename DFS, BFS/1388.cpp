#include <iostream>

using namespace std;

int n, m, result;
int check[51][51];
char graph[51][51];

bool dfs(int x, int y, char ch){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;

    char now = graph[x][y];
    if(check[x][y] == 0 && now == ch && now == '-'){
        check[x][y] = 1;
        dfs(x, y + 1, now);
        return true;
    }
    else if(check[x][y] == 0 && now == ch && now == '|'){
        check[x][y] = 1;
        dfs(x + 1, y, now);
        return true;
    }
    return false;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(check[i][j] == 1) continue;
            if(dfs(i, j, graph[i][j])) result++;
        }
    }
    cout << result << '\n';
    return 0;
}