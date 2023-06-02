#include <iostream>

using namespace std;

int n, result;
int flag_a[29];
int flag_b[29];
int flag_c[29];

void set(int x){
    for(int i = 0; i < n; i++){
        if(!flag_a[i] && !flag_b[x + i] && !flag_c[n - 1 - i + x]){
            if(x == n - 1) result++;
            else{
                flag_a[i] = flag_b[x + i] = flag_c[n - 1 - i + x] = 1;
                set(x + 1);
                flag_a[i] = flag_b[x + i] = flag_c[n - 1 - i + x] = 0;
            }
        }
    }
}

int main(void){
    cin >> n;
    set(0);
    cout << result << '\n';
    return 0;
}