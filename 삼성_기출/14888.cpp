#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, max_value = -1e9, min_value = 1e9;
int arr[11];
char oper[4] = {'+', '-', '*', '/'};
vector<char> v;

int calc(){
    int tmp = arr[0];
    int idx = 0;
    for(int i = 1; i <= n - 1; i++){
        int now = arr[i];
        char op = v[idx];
        switch (op)
        {
            case '+':
                tmp += now;
                break;
            case '-':
                tmp -= now;
                break;
            case '*':
                tmp *= now;
                break;
            case '/':
                tmp /= now;
                break;
        }
        idx++;
    }
    return tmp;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < 4; i++){
        int x;
        cin >> x;
        for(int j = 0; j < x; j++) v.push_back(oper[i]);
    }
    sort(v.begin(), v.end());

    do{
        int tmp = calc();
        max_value = max(max_value, tmp);
        min_value = min(min_value, tmp);
    }while(next_permutation(v.begin(), v.end()));
    cout << max_value << '\n' << min_value << '\n';
    return 0;
}