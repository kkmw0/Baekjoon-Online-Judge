#include <iostream>

using namespace std;

int main(void){
    int n, cnt = 0, tmp = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(x == tmp){
            tmp = (tmp + 1) % 3;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}