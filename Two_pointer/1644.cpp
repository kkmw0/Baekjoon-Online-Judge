#include <iostream>

using namespace std;

int n, cnt = 1;
int prime[300001];

void find_prime(){
    prime[cnt++] = 2, prime[cnt++] = 3;
    for(int i = 5; i <= n; i += 2){
        bool flag = false;
        for(int j = 1; prime[j] * prime[j] <= i; j++){
            if(i % prime[j] == 0){
                flag = true;
                break;
            }
        }
        if(!flag) prime[cnt++] = i;
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    find_prime();

    int j = 0, value = 0, result = 0;
    for(int i = 1; i <= cnt; i++){
        while(j + 1 <= cnt && value < n){
            value += prime[j + 1];
            j++;
        }

        if(value < n) break;
        if(value == n) result++;
        value -= prime[i];
    }
    cout << result << '\n';
    return 0;
}