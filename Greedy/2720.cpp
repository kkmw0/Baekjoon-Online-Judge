#include <iostream>

using namespace std;

int t, c;
int coin[4] = {25, 10, 5, 1};

int main(void){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> c;

        int result[4] = {0, 0, 0, 0};
        for(int j = 0; j < 4; j++){
            if(c / coin[j]){
                result[j] = c / coin[j];
                c %= coin[j];
            }
        }
        cout << result[0] << ' ' << result[1] << ' ' << result[2] << ' ' << result[3] << '\n';
    }
    return 0;
}