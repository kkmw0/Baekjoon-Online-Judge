#include <iostream>

using namespace std;

int n, blue, white;
int arr[128][128];

void dfs(int x, int y, int size){
    if(size == 1){
        if(arr[x][y] == 0) white++;
        else blue++;
        return;
    }

    bool is_white = true, is_blue = true;
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(arr[i][j] == 1) is_white = false;
            if(arr[i][j] == 0) is_blue = false;
        }
    }

    if(is_white || is_blue){
        if(is_white) white++;
        else blue++;
        return;
    }

    dfs(x, y, size / 2);
    dfs(x, y + size / 2, size / 2);
    dfs(x + size / 2, y, size / 2);
    dfs(x + size / 2, y + size / 2, size / 2);
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    dfs(0, 0, n);
    cout << white << '\n' << blue << '\n';
    return 0;
}