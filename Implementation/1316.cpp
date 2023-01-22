#include <iostream>
#include <cstring>

using namespace std;

int n, result;
int arr[26];
string str;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;

        bool flag = 0;
        memset(arr, 0, sizeof(int) * 26);
        for(int j = 0; j < str.size(); ){
            char now = str[j];
            int cnt = 0;
        
            if(arr[str[j] - 'a'] != 0){
                flag = 1;
                break;
            }
            for(int k = j; str[k] != '\0' && str[k] == now; k++) cnt++;
            arr[str[j] - 'a']++;
            j += cnt;
        }
        if(!flag) result++;
    }
    cout << result << '\n';
    return 0;
}