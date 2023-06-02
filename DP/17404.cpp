#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, result = 1e9;
int rgb[3][1001];
int d[3][1001];

void get_cost(){
    for(int i = 2; i <= n; i++){
        d[0][i] = min(d[1][i - 1], d[2][i - 1]) + rgb[0][i];
        d[1][i] = min(d[0][i - 1], d[2][i - 1]) + rgb[1][i];
        d[2][i] = min(d[0][i - 1], d[1][i - 1]) + rgb[2][i];
    }    
}

void select_red(){
    d[0][1] = rgb[0][1], d[1][1] = INF, d[2][1] = INF;
    get_cost();
    result = min({result, d[1][n], d[2][n]});
}

void select_green(){
    d[0][1] = INF, d[1][1] = rgb[1][1], d[2][1] = INF;
    get_cost();
    result = min({result, d[0][n], d[2][n]});
}

void select_blue(){
    d[0][1] = INF, d[1][1] = INF, d[2][1] = rgb[2][1];
    get_cost();
    result = min({result, d[0][n], d[1][n]});
}

void solve(){
    select_red();
    select_green();
    select_blue();
    cout << result << '\n';
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
    }
    solve();
    return 0;
}