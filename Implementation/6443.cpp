#include <iostream>
#include <algorithm>

using namespace std;

string str;
int n;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        sort(str.begin(), str.end());
        do{
            cout << str << '\n';
        } while(next_permutation(str.begin(), str.end()));
    }
    return 0;
}