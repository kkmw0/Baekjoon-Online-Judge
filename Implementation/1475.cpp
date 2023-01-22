#include <iostream>

using namespace std;

string str;
int result = 1;
int arr[10];

void add(int now){
    for(int i = 0; i < 10; i++){
        arr[i]++;
    }
    arr[now]--;
    result++;
}

int main(void){
    cin >> str;

    fill_n(arr, 10, 1);
    for(int i = 0; i < str.size(); i++){
        int now = str[i] - '0';
        if(arr[now] == 0){
            if(now == 6){
                if(arr[9] != 0) arr[9]--;
                else add(now);
            }
            else if(now == 9){
                if(arr[6] != 0) arr[6]--;
                else add(now);
            }
            else add(now);
        }
        else arr[now]--;
    }
    cout << result << '\n';
    return 0;
}