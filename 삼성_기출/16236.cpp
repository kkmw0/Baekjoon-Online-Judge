#include <iostream>
#include <queue>

using namespace std;

struct Shark{
    int x, y, t;
};

bool update;
int n, shark_size, eat_cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[20][20];
Shark s, tmp;

void bfs(){
    bool visited[20][20] = {false, };
    queue<Shark> q;
    q.push(s);
    visited[s.x][s.y] = true;

    tmp = {20, 20, -1};
    while(!q.empty()){
        Shark now = q.front();
        q.pop();

        if(tmp.t != -1 && now.t > tmp.t) break;
        if(board[now.x][now.y] != 0 && shark_size > board[now.x][now.y]){
            update = true;
            if(tmp.x > now.x || (tmp.x == now.x && tmp.y > now.y)){
                tmp = now;
            }
        }

        for(int i = 0; i < 4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(nx < 0 || ny < 0 || nx >=n || ny >= n) continue;
            if(shark_size >= board[nx][ny] && !visited[nx][ny]){
                Shark next = {nx, ny, now.t + 1};
                q.push(next);
                visited[nx][ny] = true;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 9){
                s.x = i, s.y = j, s.t = 0;
                shark_size = 2, eat_cnt = 0;
                board[i][j] = 0;
            }
        }
    }

    update = true;
    while(update){
        update = false;
        bfs();
        if(update){
            s = tmp;
            eat_cnt++;
            if(shark_size == eat_cnt){
                shark_size++;
                eat_cnt = 0;
            }
            board[s.x][s.y] = 0;
        }
    }
    cout << s.t << '\n';
    return 0;
}