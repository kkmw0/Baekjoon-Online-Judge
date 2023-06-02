#include <iostream>

using namespace std;

struct Robot{
    int x, y, dir;
};

int a, b, n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int robot_map[101][101];
Robot robot[101];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> n >> m;
    for(int i = 1; i <= n; i++){
        int x, y, tmp; char ch;
        cin >> x >> y >> ch;

        if(ch == 'N') tmp = 0;
        else if(ch == 'E') tmp = 1;
        else if(ch == 'S') tmp = 2;
        else tmp = 3;
        robot[i] = {x, y, tmp};
        robot_map[x][y] = i;
    }

    int crash_wall = 0, crash_robot = 0, last_robot = 0;
    for(int i = 0; i < m; i++){
        int idx, repeat; char cmd;
        cin >> idx >> cmd >> repeat;

        if(crash_wall || crash_robot) continue;

        int x = robot[idx].x;
        int y = robot[idx].y;
        int d = robot[idx].dir;

        while(repeat--){
            if(cmd == 'F'){
                robot_map[x][y] = 0;
                x += dx[d];
                y += dy[d];

                if(x < 1 || y < 1 || x > a || y > b){
                    crash_wall = idx;
                    break;
                }
                if(robot_map[x][y] != 0){
                    last_robot = idx;
                    crash_robot = robot_map[x][y];
                    break;
                }
                robot[idx].x = x;
                robot[idx].y = y;
                robot_map[x][y] = idx;
            }
            else if(cmd == 'L'){
                d = (d + 3) % 4;
                robot[idx].dir = d;
            }
            else{
                d = (d + 1) % 4;
                robot[idx].dir = d;
            }
        }
    }
    if(crash_wall) cout << "Robot " << crash_wall << " crashes into the wall\n";
    else if(crash_robot) cout << "Robot " << last_robot << " crashes into robot " << crash_robot << '\n';
    else cout << "OK" << '\n';
    return 0;
}