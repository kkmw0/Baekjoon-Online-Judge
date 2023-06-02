#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int n, s, result;
int arr[20];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int p = pow(2, n);
    for(int i = 0; i < p; i++){
        bitset<20> bits(i);

        bool flag = false;
        int tmp = 0;
        for(int j = 0; j < n; j++){
            if(bits[j]){
                tmp += arr[j];
                flag = true;
            }
        }
        if(tmp == s && flag) result++;
    }
    cout << result << '\n';
    return 0;
}
