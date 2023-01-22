#include <iostream>

using namespace std;

string str;
int n;

int main(void){
    cin >> n >> str;

    int cnt = 0;
    for(int i = 0; i < n - 3; ){
        if(str[i] == 'p' && str[i + 1] == 'P' && str[i + 2] == 'A' && str[i + 3] == 'p'){
            cnt++;
            i += 4;
        }
        else i++;
    }
    cout << cnt << '\n';
    return 0;
}