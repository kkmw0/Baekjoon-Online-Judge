#include <iostream>
#include <vector>

using namespace std;

struct Fireball{
    int x, y, m, s, d;
};

int n, m, k;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<Fireball> ball;
vector<int> board[50][50];

void move_ball(){
    vector<int> tmp[50][50];
    for(int i = 0; i < ball.size(); i++){
        int s = (ball[i].s % n);
        int d = ball[i].d;
        int nx = (ball[i].x + dx[d] * s + n) % n;
        int ny = (ball[i].y + dy[d] * s + n) % n;

        tmp[nx][ny].push_back(i);
        ball[i].x = nx;
        ball[i].y = ny;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] = tmp[i][j];
        }
    }
}

void sum_ball(){
    vector<Fireball> tmp;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(board[x][y].size() == 0) continue;
            if(board[x][y].size() == 1){
                int idx = board[x][y][0];
                tmp.push_back(ball[idx]);
                continue;
            }

            int sum_m = 0, sum_s = 0;
            bool odd = true, even = true;
            for(int i = 0; i < board[x][y].size(); i++){
                int idx = board[x][y][i];
                sum_m += ball[idx].m;
                sum_s += ball[idx].s;

                if(ball[idx].d % 2 == 0) odd = false;
                else even = false;
            }

            if(sum_m / 5 == 0) continue;

            int cur_m = sum_m / 5;
            int cur_s = sum_s / board[x][y].size();
            for(int i = 0; i < 4; i++){
                if(odd || even) tmp.push_back({x, y, cur_m, cur_s, i * 2});
                else tmp.push_back({x, y, cur_m, cur_s, i * 2 + 1});
            }
        }
    }
    ball = tmp;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        x--, y--;
        ball.push_back({x, y, m, s, d});
        board[x][y].push_back(i);
    }

    for(int i = 0; i < k; i++){
        move_ball();
        sum_ball();
    }

    int result = 0;
    for(int i = 0; i < ball.size(); i++){
        result += ball[i].m;
    }
    cout << result << '\n';
    return 0;
}