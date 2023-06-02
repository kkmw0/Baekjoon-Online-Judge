#include <iostream>

using namespace std;

int n, m, z, p;
int arr[2187][2187];

void dfs(int x, int y, int size){
    if(size == 1){
        if(arr[x][y] == -1) m++;
        else if(arr[x][y] == 0) z++;
        else p++;
        return;
    }

    bool is_minus = true, is_zero = true, is_plus = true;
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(arr[i][j] == -1){
                is_zero = false;
                is_plus = false;
            }
            else if(arr[i][j] == 0){
                is_minus = false;
                is_plus = false;
            }
            else{
                is_minus = false;
                is_zero = false;
            }
        }
    }

    if(is_minus || is_zero || is_plus){
        if(is_minus) m++;
        else if(is_zero) z++;
        else if(is_plus) p++;
        return;
    }

    dfs(x, y, size / 3);
    dfs(x, y + size / 3, size / 3);
    dfs(x + size / 3, y, size / 3);
    dfs(x + size / 3, y + size / 3, size / 3);
    dfs(x, y + 2 * size / 3, size / 3);
    dfs(x + 2 * size / 3, y, size / 3);
    dfs(x + 2 * size / 3, y + 2 * size / 3, size / 3);
    dfs(x + size / 3, y + 2 * size / 3, size / 3);
    dfs(x + 2 * size / 3, y + size / 3, size / 3);
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
    cout << m << '\n' << z << '\n' << p << '\n';
    return 0;
}