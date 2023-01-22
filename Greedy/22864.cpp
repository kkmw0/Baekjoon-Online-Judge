#include <iostream>

using namespace std;

int a, b, c, m;

int main(void){
    cin >> a >> b >> c >> m;

    int result = 0;
    int fatigue = 0;
    for(int i = 0; i < 24; i++){
        if(m - fatigue >= a){
            result += b;
            fatigue += a;
        }
        else{
            fatigue -= c;
            if(fatigue < 0) fatigue = 0;
        }
    }
    cout << result << '\n';
    return 0;
}