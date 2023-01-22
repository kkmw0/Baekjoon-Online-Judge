#include <iostream>
#include <vector>

using namespace std;

int n, max_value, cnt, ans;
vector<int> v;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    for(int i = 0; i < n; i++){
        if(v[i] > max_value){
            max_value = v[i];
            cnt = 0;
        }
        else cnt++;
        ans = ans > cnt ? ans : cnt;
    }
    cout << ans << '\n';
    return 0;
}