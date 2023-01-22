#include <iostream>
#include <algorithm>

using namespace std;

int start, mid, last;

int main(void){
    while(cin >> start >> mid >> last){
        cout << max(mid - start - 1, last - mid - 1) << '\n';
    }
    return 0;
}