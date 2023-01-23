#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt, num;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int graph[25][25];
bool check[25][25];
vector<int> result;

void dfs(int x, int y){
    check[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(graph[nx][ny] == 0) continue;
        else{
            if(!check[nx][ny]){
                num++;
                dfs(nx, ny);
            }
        }
    }
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &graph[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] != 0 && !check[i][j]){
                num = 1;
                dfs(i, j);
                result.push_back(num);
                cnt++;
            }
        }
    }
    sort(result.begin(), result.end());
    
    cout << cnt << '\n';
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << '\n';
    }
    return 0;
}
