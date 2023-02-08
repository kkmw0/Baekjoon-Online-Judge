#include <iostream>

using namespace std;

string str;
int n, x;
int arr[4];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str >> x;
        if(str == "STRAWBERRY") arr[0] += x;
        else if(str == "BANANA") arr[1] += x;
        else if(str == "LIME") arr[2] += x;
        else arr[3] += x;
    }
    for(int i = 0; i < 4; i++){
        if(arr[i] == 5){
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}