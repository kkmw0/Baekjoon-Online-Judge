#include <iostream>
#include <algorithm>

using namespace std;

int t, j, n;

bool cmp(int a, int b){
    return a > b;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int test_case = 0; test_case < t; test_case++){
        int r[1000] = {0, }, c[1000] = {0, }, box[1000] = {0, };
        int result = 0;

        cin >> j >> n;
        for(int i = 0; i < n; i++){
            cin >> r[i] >> c[i];
            int value = r[i] * c[i];
            box[i] = value;
        }
        sort(box, box + n, cmp);
        
        for(int i = 0; i < n; i++){
            int now = box[i];
            if(now >= j){
                result++;
                break;
            }
            else{
                result++;
                j -= box[i];
            }
        }
        cout << result << '\n';
    }
    return 0;
}