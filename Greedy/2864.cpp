#include <iostream>
#include <string>

using namespace std;

string a, b;
int ans[2];

int main(void){
    cin >> a >> b;
    int len_a = a.size();
    int len_b = b.size();

    for(int i = 0; i < len_a; i++) if(a[i] == '6') a[i] = '5';
    for(int i = 0; i < len_b; i++) if(b[i] == '6') b[i] = '5';
    ans[0] = stoi(a) + stoi(b);

    for(int i = 0; i < len_a; i++) if(a[i] == '5') a[i] = '6';
    for(int i = 0; i < len_b; i++) if(b[i] == '5') b[i] = '6';
    ans[1] = stoi(a) + stoi(b);

    cout << ans[0] << ' ' << ans[1] << '\n';
    return 0;
}