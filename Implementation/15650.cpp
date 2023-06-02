#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++) arr[i] = i + 1;

    vector<int> v(m, 1);
    for(int i = 0; i < n - m; i++) v.push_back(0);
    do{
        for(int i = 0; i < v.size(); i++){
            if(v[i] == 1) cout << arr[i] << ' ';
        }
        cout << '\n';
    } while(prev_permutation(v.begin(), v.end()));
    return 0;
}