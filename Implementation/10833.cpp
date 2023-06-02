#include <iostream>

using namespace std;

int n, s;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int stu, apple;
        cin >> stu >> apple;
        s += (apple % stu);
    }
    cout << s << '\n';
    return 0;
}