#include <iostream>
#include <algorithm>

using namespace std;

int arr[21];

int main(void){
    for(int i = 1; i <= 20; i++) arr[i] = i;
    for(int i = 0; i < 10; i++){
        int first, second;
        cin >> first >> second;

        int start = first, end = second;
        while(start <= end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    for(int i = 1; i <= 20; i++) cout << arr[i] << ' ';
    return 0;
}