#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int graph[5][5];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
set<string> str;

void dfs(int x, int y, int move, string tmp){
    if(x < 0 || y < 0 || x >= 5 || y >= 5) return;
    if(move == 6) str.insert(tmp);
    else{
        for(int i = 0; i < 4; i++){
            dfs(x + dx[i], y + dy[i], move + 1, tmp + (char)graph[x][y]);
        }
    }
}

int main(void){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> graph[i][j];
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            dfs(i, j, 0, "");
        }
    }
    cout << str.size() << '\n';
    return 0;
}