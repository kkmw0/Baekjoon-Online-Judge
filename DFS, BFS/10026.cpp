#include <iostream>

using namespace std;

int n, res1, res2;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited1[100][100];
bool visited2[100][100];
char graph1[100][100];
char graph2[100][100];

void dfs1(int x, int y, char ch){
    visited1[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(graph1[nx][ny] == ch && !visited1[nx][ny]) dfs1(nx, ny, ch);
    }
}

void dfs2(int x, int y, char ch){
    visited2[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(graph2[nx][ny] == ch && !visited2[nx][ny]) dfs2(nx, ny, ch);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph1[i][j];
            if(graph1[i][j] == 'G') graph2[i][j] = 'R';
            else graph2[i][j] = graph1[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph1[i][j] == 'R' && !visited1[i][j]) { dfs1(i, j, 'R'); res1++;}
            else if(graph1[i][j] == 'G' && !visited1[i][j]) { dfs1(i, j, 'G'); res1++;}
            else if(graph1[i][j] == 'B' && !visited1[i][j]) { dfs1(i, j, 'B'); res1++;}
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph2[i][j] == 'R' && !visited2[i][j]) { dfs2(i, j, 'R'); res2++; }
            else if(graph2[i][j] == 'B' && !visited2[i][j]) { dfs2(i, j, 'B'); res2++; }
        }
    }
    cout << res1 << ' ' << res2 << '\n';
    return 0;
}
