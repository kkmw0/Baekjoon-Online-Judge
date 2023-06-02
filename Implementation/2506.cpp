#include <iostream>

using namespace std;

int n, x, result, st = 1;
bool flag = false;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 1){
            if(flag == false) flag = true;
            result += st;
            st++;
        }
        else{
            flag = false;
            st = 1;
        }
    }
    cout << result << '\n';
    return 0;
}