#include <iostream>
#include <algorithm>

using namespace std;

long long b, c, d, origin, sets;
int buger[1000], side[1000], drink[1000];

bool cmp(int a, int b){
    return a > b;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> b >> c >> d;
    for(int i = 0; i < b; i++){
        cin >> buger[i];
        origin += buger[i];
    }
    for(int i = 0; i < c; i++){
        cin >> side[i];
        origin += side[i];
    }
    for(int i = 0; i < d; i++){
        cin >> drink[i];
        origin += drink[i];
    }
    sort(buger, buger + b, cmp);
    sort(side, side + c, cmp);
    sort(drink, drink + d, cmp);

    int len = min({b, c, d});
    for(int i = 0; i < len; i++){
        sets += (buger[i] + side[i] + drink[i]) * 0.9;
    }
    for(int i = len; i < b; i++) sets += buger[i];
    for(int i = len; i < c; i++) sets += side[i];
    for(int i = len; i < d; i++) sets += drink[i];

    cout << origin << '\n' << sets << '\n';
    return 0;
}