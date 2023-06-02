#include <iostream>

using namespace std;

struct Point{
    double x, y;
};

int n;
Point point[10001];

void solve(){
    long double result = 0;
    double p_x = point[0].x, p_y = point[0].y;
    for(int i = 1; i < n - 1; i++){
        result += ((point[i].x - p_x) * (point[i + 1].y - p_y) - (point[i + 1].x - p_x) * (point[i].y - p_y)) / 2;
    }
    if(result < 0) result *= -1;

    cout << fixed;
    cout.precision(1);
    cout << result << '\n';
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> point[i].x >> point[i].y;
    }
    solve();
    return 0;
}