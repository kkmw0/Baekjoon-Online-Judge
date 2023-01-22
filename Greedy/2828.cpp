#include <iostream>

using namespace std;

int n, m, j, apple, result;

int main(void){
    cin >> n >> m >> j;

    int left = 1;
    int right = m;
    for(int i = 0; i < j; i++){
        cin >> apple;
        if(apple >= left && apple <= right) continue;
        else{
            if(apple > right){
                result += apple - right;
                left += apple - right;
                right += apple - right;
            }
            else if(apple < left){
                result += left - apple;
                right -= left - apple;
                left -= left - apple;
            }
        }
    }
    cout << result << '\n';
    return 0;
}