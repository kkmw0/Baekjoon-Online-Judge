#include <iostream>

using namespace std;

int r, c, k, result;
int prev_rsize = 3, cur_rsize = 3, prev_csize = 3, cur_csize = 3;
int arr[101][101];

void update_row(int x){
    int bucket[101] = {0, };
    for(int i = 1; i <= prev_csize; i++){
        bucket[arr[x][i]]++;
    }

    int size = 0;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            if(bucket[j] == i){
                arr[x][++size] = j;
                arr[x][++size] = i;

                if(size == 100) break;
            }
        }
        if(size == 100) break;
    }
    for(int i = size + 1; i <= 100; i++) arr[x][i] = 0;
    if(size > cur_csize) cur_csize = size;
}

void update_col(int y){
    int bucket[101] = {0, };
    for(int i = 1; i <= prev_rsize; i++){
        bucket[arr[i][y]]++;
    }

    int size = 0;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            if(bucket[j] == i){
                arr[++size][y] = j;
                arr[++size][y] = i;

                if(size == 100) break;
            }
        }
        if(size == 100) break;
    }
    for(int i = size + 1; i <= 100; i++) arr[i][y] = 0;
    if(size > cur_rsize) cur_rsize = size;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> k;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> arr[i][j];
        }
    }

    while(arr[r][c] != k){
        if(cur_rsize >= cur_csize){
            prev_csize = cur_csize;
            cur_csize = 0;
            for(int i = 1; i <= cur_rsize; i++) update_row(i);
        }
        else{
            prev_rsize = cur_rsize;
            cur_rsize = 0;
            for(int i = 1; i <= cur_csize; i++) update_col(i);
        }

        result++;
        if(result > 100) break;
    }

    if(result > 100) cout << -1 << '\n';
    else cout << result << '\n';
    return 0;
}