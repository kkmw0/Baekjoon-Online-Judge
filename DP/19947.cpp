#include <iostream>
#include <algorithm>

using namespace std;

int h, y;
int d[11];

int main(void){
    cin >> h >> y;
    d[0] = h;
    for(int i = 1; i <= y; i++){
        d[i] = static_cast<int>(d[i - 1] * 1.05);
        if(i / 3) d[i] = max(d[i], static_cast<int>(d[i - 3] * 1.2));
        if(i / 5) d[i] = max(d[i], static_cast<int>(d[i - 5] * 1.35));
    }
    cout << d[y] << '\n';
    return 0;
}