#include <iostream>

using namespace std;

int n, y, m;
int arr[20];

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        y += 10 + 10 * (arr[i] / 30);
        m += 15 + 15 * (arr[i] / 60);
    }
    if(y == m) cout << "Y M " << y;
    else if(y > m) cout << "M " << m;
    else cout << "Y " << y;
    return 0;
}