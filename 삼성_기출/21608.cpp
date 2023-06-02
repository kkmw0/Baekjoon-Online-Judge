#include <iostream>

using namespace std;

struct Student{
    int num;
    int x, y;
    int f[4];
};

int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int point[5] = {0, 1, 10, 100, 1000};
int arr[21][21];
Student s[400];

int calc(int idx){
    int cnt = 0;
    int now_x = s[idx].x, now_y = s[idx].y;
    for(int d = 0; d < 4; d++){
        int nx = now_x + dx[d];
        int ny = now_y + dy[d];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        
        for(int i = 0; i < 4; i++){
            if(arr[nx][ny] == s[idx].f[i]){
                cnt++;
                break;
            }
        }
    }
    return point[cnt];
}

void sit(int x, int y, int idx){
    s[idx].x = x; s[idx].y = y;
    arr[x][y] = s[idx].num;
}

int get_score(int x, int y, int idx){
    int score = 0;
    for(int d = 0; d < 4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(arr[nx][ny] == 0) score++;
        else{
            for(int i = 0; i < 4; i++){
                if(arr[nx][ny] == s[idx].f[i]) score += 10;
            }
        }
    }
    return score;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n * n; i++){
        cin >> s[i].num >> s[i].f[0] >> s[i].f[1] >> s[i].f[2] >> s[i].f[3];
    }

    for(int i = 0; i < n * n; i++){
        int now_x = -1, now_y = -1, score = -1;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(arr[x][y] == 0){
                    int now_score = get_score(x, y, i);
                    if(now_score > score){
                        now_x = x;
                        now_y = y;
                        score = now_score;
                    }
                }
            }
        }
        sit(now_x, now_y, i);
    }
    int result = 0;
    for(int i = 0; i < n * n; i++){
        result += calc(i);
    }
    cout << result << '\n';
    return 0;
}