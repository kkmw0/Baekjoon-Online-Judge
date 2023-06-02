#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;
int arr[14];

int main(void){
    while(true){
        cin >> k; if(k == 0) break;
        for(int i = 0; i < k; i++) cin >> arr[i];

        vector<int> v(6, 1);
        for(int i = 0; i < k - 6; i++) v.push_back(0);

        do{
            for(int i = 0; i < v.size(); i++){
                if(v[i] == 1) cout << arr[i] << ' ';
            }
            cout << '\n';
        } while(prev_permutation(v.begin(), v.end()));
        cout << '\n';
    }
    return 0;
}