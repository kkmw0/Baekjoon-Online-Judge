#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[26];
string result;
vector<string> str;

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        str.push_back(s);
    }

    int hamming = 0;
    for(int i = 0; i < m; i++){
        int max_value = 0;
        int idx = 0;
        fill_n(arr, 26, 0);

        for(int j = 0; j < n; j++) arr[str[j][i] - 'A']++;
        for(int i = 0; i < 26; i++){
            if(arr[i] > max_value){
                max_value = arr[i];
                idx = i;
            }
        }
        result += idx + 'A';
        for(int j = 0; j < n; j++){
            if(result[i] == str[j][i]) continue;
            else hamming++;
        }
    }
    cout << result << '\n' << hamming << '\n';
    return 0;
}