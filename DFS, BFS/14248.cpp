#include <iostream>

using namespace std;

int n, s, result = 1;
int arr[100001];
bool check[100001];

void dfs(int x){
    check[x] = true;
    int pos1 = x + arr[x];
    int pos2 = x - arr[x];

    if(pos1 >= 1 && pos1 <= n && !check[pos1]){
        result++;
        dfs(pos1);
    }
    if(pos2 >= 1 && pos2 <= n && !check[pos2]){
        result++;
        dfs(pos2);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cin >> s;
    dfs(s);
    cout << result << '\n';
    return 0;
}