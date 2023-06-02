#include <iostream>

using namespace std;

int n, v;
int arr[201];

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[x + 100]++;
    }
    cin >> v;
    cout << arr[v + 100] << '\n';
    return 0;
}