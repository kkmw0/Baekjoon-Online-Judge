#include <iostream>

using namespace std;

int n, m;
int arr[100001];
int s[100001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }
    for(int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;
        cout << s[end] - s[start - 1] << '\n';
    }
    return 0;
}