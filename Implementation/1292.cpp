#include <iostream>

using namespace std;

int a, b, result;
int arr[1001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for(int i = 1, value = 1; i <= 1000; value++){
        int cnt = 0;
        for(int j = 0; j < value; j++, cnt++){
            if(i + j > 1000){
                i += 1000;
                break;
            }
            arr[i + j] = value;
        }
        i += cnt;
    }
    for(int i = a; i <= b; i++) result += arr[i];
    cout << result << '\n';
    return 0;
}