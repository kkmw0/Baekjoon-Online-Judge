#include <iostream>

using namespace std;

struct AB{
    int a;
    int b;
};

int n;
AB d[46];

int main(void){
    cin >> n;
    d[0].a = 1; d[0].b = 0;
    for(int i = 1; i <= n; i++){
        d[i].a = d[i - 1].b;
        d[i].b = d[i - 1].a + d[i - 1].b;
    }
    cout << d[n].a << ' ' << d[n].b << '\n';
    return 0;
}