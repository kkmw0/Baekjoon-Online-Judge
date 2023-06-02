#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree{
    int x, y, age;
};

int n, m, k;
int arr[11][11];
int add[11][11];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<Tree> tree;
vector<int> board[11][11];

void eat(){
    vector<Tree> tmp;
    vector<int> new_board[11][11];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sort(board[i][j].begin(), board[i][j].end());
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int value = 0;
            for(int k = 0; k < board[i][j].size(); k++){
                int now_age = board[i][j][k];
                if(arr[i][j] >= now_age){
                    arr[i][j] -= now_age;
                    now_age++;
                    tmp.push_back({i, j, now_age});
                    new_board[i][j].push_back(now_age);
                }
                else value += now_age / 2;
            }
            arr[i][j] += value;
        }
    }

    tree = tmp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] = new_board[i][j];
        }
    }
}

void spread(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < board[i][j].size(); k++){
                int now_age = board[i][j][k];
                if(now_age % 5 != 0) continue;

                for(int d = 0; d < 8; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    tree.push_back({nx, ny, 1});
                    board[nx][ny].push_back(1);
                }
            }
        }
    }
}

void add_arr(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] += add[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> add[i][j];
            arr[i][j] = 5;
        }
    }
    for(int i = 0; i < m; i++){
        int r, c, age;
        cin >> r >> c >> age;
        r--, c--;
        tree.push_back({r, c, age});
        board[r][c].push_back(age);
    }

    for(int i = 0; i < k; i++){
        eat();
        spread();
        add_arr();
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result += board[i][j].size();
        }
    }
    cout << result << '\n';
    return 0;
}