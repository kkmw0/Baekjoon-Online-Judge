#include <iostream>

using namespace std;

int n, result;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int arr[101][101];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        int curv_size = 0;
        int curve[1024] = {0, };

        curve[curv_size++] = d;
        arr[y][x] = 1;
        for(int j = 0; j < g; j++){
            for(int k = curv_size - 1; k >= 0; k--){
                curve[curv_size++] = (curve[k] + 1) % 4;
            }
        }

        for(int j = 0; j < curv_size; j++){
            y += dy[curve[j]];
            x += dx[curve[j]];

            if(y < 0 || x < 0 || y > 100 || x > 100) continue;
            arr[y][x] = 1;
        }
    }

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(arr[i][j] && arr[i][j + 1] && arr[i + 1][j] && arr[i + 1][j + 1]){
                result++;
            }
        }
    }
    cout << result << '\n';
    return 0;
}