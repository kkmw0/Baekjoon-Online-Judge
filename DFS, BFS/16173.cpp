#include <iostream>

using namespace std;

int n;
int graph[4][4];

bool dfs(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= n) return false;
    if(graph[x][y] == 0) return false;
    if(x == n - 1 && y == n - 1) return true;
    return dfs(x + graph[x][y], y) || dfs(x, y + graph[x][y]);
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    if(dfs(0, 0)) cout << "HaruHaru" << '\n';
    else cout << "Hing" << '\n';
    return 0;
}