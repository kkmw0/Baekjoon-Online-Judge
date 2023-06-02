#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Pos{
    int r_x, r_y;
    int b_x, b_y;
    int cnt;
};

Pos start;
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char graph[11][11];
bool visited[11][11][11][11];

int bfs(){
    queue<Pos> q;
    q.push(start);
    visited[start.r_x][start.r_y][start.b_x][start.b_y] = true;

    while(!q.empty()){
        Pos now = q.front();
        int cost = now.cnt;
        q.pop();

        if(cost > 10) return -1;
        if(graph[now.r_x][now.r_y] == 'O' && graph[now.b_x][now.b_y] != 'O') return cost;

        for(int i = 0; i < 4; i++){
            int nr_x = now.r_x;
            int nr_y = now.r_y;
            int nb_x = now.b_x;
            int nb_y = now.b_y;

            // Red
            while(true){
                if(graph[nr_x][nr_y] != '#' && graph[nr_x][nr_y] != 'O'){
                    nr_x += dx[i];
                    nr_y += dy[i];
                }
                else{
                    if(graph[nr_x][nr_y] == '#'){
                        nr_x -= dx[i];
                        nr_y -= dy[i];                        
                    }
                    break;
                }
            }
            // Blue
            while(true){
                if(graph[nb_x][nb_y] != '#' && graph[nb_x][nb_y] != 'O'){
                    nb_x += dx[i];
                    nb_y += dy[i];
                }
                else{
                    if(graph[nb_x][nb_y] == '#'){
                        nb_x -= dx[i];
                        nb_y -= dy[i];                  
                    }
                    break;
                }
            }

            if(nr_x == nb_x && nr_y == nb_y){
                if(graph[nr_x][nr_y] != 'O'){
                    int dist_r = abs(nr_x - now.r_x) + abs(nr_y - now.r_y);
                    int dist_b = abs(nb_x - now.b_x) + abs(nb_y - now.b_y);
                    if(dist_r > dist_b){
                        nr_x -= dx[i];
                        nr_y -= dy[i];
                    }
                    else{
                        nb_x -= dx[i];
                        nb_y -= dy[i];
                    }                    
                }
            }

            if(!visited[nr_x][nr_y][nb_x][nb_y]){
                visited[nr_x][nr_y][nb_x][nb_y] = true;
                Pos next = {nr_x, nr_y, nb_x, nb_y, cost + 1};
                q.push(next);
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'R'){
                start.r_x = i;
                start.r_y = j;
            }
            else if(graph[i][j] == 'B'){
                start.b_x = i;
                start.b_y = j;
            }
        }
    }
    int result = bfs();
    cout << result << '\n';
    return 0;
}