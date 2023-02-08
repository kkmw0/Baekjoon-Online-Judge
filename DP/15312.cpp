#include <iostream>
#include <string>

using namespace std;

string a, b, c;
int cnt[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int d[4002];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++){
        c += a[i];
        c += b[i];
    }

    int len = c.size();
    for(int i = 0; i < len; i++) d[i] = cnt[c[i] - 'A'];

    for(int i = 0; i < len - 2; i++){
        for(int j = 0; j < len - i - 1; j++){
            d[j] = (d[j] + d[j + 1]) % 10;
        }
    }
    string result = to_string(d[0]) + to_string(d[1]);
    cout << result << '\n';
    return 0;
}