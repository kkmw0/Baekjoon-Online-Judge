#include <iostream>

using namespace std;

int n, r, c;

int solve(int d, int row, int col){
    if(d == 0) return 0;
    int half_side = 1 << (d - 1);

    if(row < half_side && col < half_side) return solve(d - 1, row, col);
    if(row < half_side && col >= half_side) return half_side * half_side + solve(d - 1, row, col - half_side);
    if(row >= half_side && col < half_side) return 2 * half_side * half_side + solve(d - 1, row - half_side, col);
    return 3 * half_side * half_side + solve(d - 1, row - half_side, col - half_side);
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r >> c;
    cout << solve(n, r, c) << '\n';
    return 0;
}