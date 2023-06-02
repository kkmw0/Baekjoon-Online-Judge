#include <iostream>

using namespace std;

struct Snake{
    int head_x, head_y, tail_idx;
    int snake_x[10101], snake_y[10101];
};

int n, k, l;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[101][101];
char command[10001];
Snake s;

void init(int t){
    s.head_x = 1, s.head_y = 1, s.tail_idx = t;
    s.snake_x[t] = s.head_x, s.snake_y[t] = s.head_y;
    board[s.head_x][s.head_y] = -1;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int x, y; cin >> x >> y;
        board[x][y] = 1;
    }

    cin >> l;
    for(int i = 0; i < l; i++){
        int t;
        char ch;
        cin >> t >> ch;
        command[t] = ch;
    }

    int t = 0, d = 0;
    init(t);
    while(true){
        t++;
        s.head_x += dx[d];
        s.head_y += dy[d];

        if(s.head_x <= 0 || s.head_y <= 0 || s.head_x > n || s.head_y > n || board[s.head_x][s.head_y] == -1) break;

        s.snake_x[t] = s.head_x;
        s.snake_y[t] = s.head_y;
        if(board[s.head_x][s.head_y] == 0){
            int tail_x = s.snake_x[s.tail_idx];
            int tail_y = s.snake_y[s.tail_idx];
            board[tail_x][tail_y] = 0;
            s.tail_idx++;
        }
        board[s.head_x][s.head_y] = -1;

        if(command[t] == 'D') d = (d + 1) % 4;
        if(command[t] == 'L') d = (d + 3) % 4;
    }
    cout << t << '\n';
    return 0;
}