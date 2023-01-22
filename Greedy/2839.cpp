#include <iostream>
#include <algorithm>

using namespace std;

int n;

/* Solve 1 : Dynamic Programing */
void Solve_1(){
    int d[5001];
    fill_n(d, 5001, 5001);

    d[3] = 1; d[5] = 1;
    for(int i = 6; i <= n; i++){
        if(d[i - 3] < 5001) d[i] = min(d[i - 3] + 1, d[i]);
        if(d[i - 5] < 5001) d[i] = min(d[i - 5] + 1, d[i]);
    }

    if(d[n] == 5001) cout << "Dynamic Programing : " << -1 << '\n';
    else cout << "Dynamic Programing : " << d[n] << '\n';
}

/* Solve 2 : Greedy */
void Solve_2(){
    int n_5 = n / 5;
    while(true){
        int tmp = n - n_5 * 5;
        if(tmp % 3 == 0){
            cout << "Greedy : " << n_5 + (n - n_5 * 5) / 3 << '\n';
            break;
        }
        n_5--;
        if(n_5 < 0){
            cout << "Greedy : " << -1 << '\n';
            break;
        }
    }
}

int main(void){
    cin >> n;
    Solve_1();
    Solve_2();
    return 0;
}