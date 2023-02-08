#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int p;
int change[9][5] = {{1, 2, 4}, {1, 2, 3, 5}, {2, 3, 6},
                    {1, 4, 5, 7}, {2, 4, 5, 6, 8}, {3, 5, 6, 9}, 
                    {4, 7, 8}, {5, 7, 8, 9}, {6, 8, 9}};
int value[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
char graph[3][3];
bool visited[513];

int bfs(string start, string end){
    queue<pair<string, int>> q;
    q.push({start, 0});
    visited[0] = true;

    while(!q.empty()){
        string now = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(now == end) return cost;

        for(int i = 0; i < 9; i++){
            string tmp = now;
            for(int j = 0; j < 5 && change[i][j] != 0; j++){
                if(now[change[i][j] - 1] == '.') tmp[change[i][j] - 1] = '*';
                else tmp[change[i][j] - 1] = '.';
            }

            int s = 0;
            for(int k = 0; k < 9; k++){
                if(tmp[k] == '*') s += value[k];
            }

            if(!visited[s]){
                visited[s] = true;
                q.push({tmp, cost + 1});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> p;
    for(int test_case = 0; test_case < p; test_case++){
        string target = "";
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cin >> graph[i][j];
                target += graph[i][j];
            }
        }
        cout << bfs(".........", target) << '\n';
        fill_n(visited, 513, false);
    }
    return 0;
}