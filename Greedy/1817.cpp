#include <iostream>

using namespace std;

int n, m;
int book[50];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> book[i];

    int box = 1, box_capacity = m;
    for(int i = 0; i < n; i++){
        int now = book[i];
        if(now <= box_capacity) box_capacity -= book[i];
        else{
            box_capacity = m;
            box_capacity -= book[i];
            box++;
        }
    }
    if(n == 0) cout << 0 << '\n';
    else cout << box << '\n';
    return 0;
}