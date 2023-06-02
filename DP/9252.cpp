#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string a, b;
int d[1001][1001];
vector<char> str;

int main(void){
    cin >> a >> b;

    int result = 0;
    int len_a = a.size(), len_b = b.size();
    for(int i = 1; i <= len_a; i++){
        for(int j = 1; j <= len_b; j++){
            if(a[i - 1] == b[j - 1]){
                d[i][j] = d[i - 1][j - 1] + 1;
                result = max(result, d[i][j]);
            }
            else d[i][j] = max(d[i][j - 1], d[i - 1][j]);
        }
    }

    int x = len_a, y = len_b;
    while(x >= 1 && y >= 1){
        if(d[x - 1][y] == d[x][y]) x--;
        else if(d[x][y - 1] == d[x][y]) y--;
        else{
            str.push_back(a[x - 1]);
            x--; y--;
        }
    }
    cout << result << '\n';
    for(int i = str.size() - 1; i >= 0; i--) cout << str[i];
    return 0;
}