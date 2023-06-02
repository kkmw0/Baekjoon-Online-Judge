#include <iostream>

using namespace std;

int n;
int arr[64][64];

void dfs(int x, int y, int size){
    if(size == 1){
        cout << arr[x][y];
        return;
    }

    bool is_zero = true, is_one = true;
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(arr[i][j] == 1) is_zero = false;
            if(arr[i][j] == 0) is_one = false;
        }
    }

    if(is_zero || is_one){
        if(is_zero) cout << 0;
        else cout << 1;
        return;
    }

    cout << "(";
    dfs(x, y, size / 2);
    dfs(x, y + size / 2, size / 2);
    dfs(x + size / 2, y, size / 2);
    dfs(x + size / 2, y + size / 2, size / 2);
    cout << ")";
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    dfs(0, 0, n);
    return 0;
}