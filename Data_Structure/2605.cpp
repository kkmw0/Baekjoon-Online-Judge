#include <iostream>
#include <list>

using namespace std;

int n;
list<int> li;
list<int>::iterator iter;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        iter = li.begin();
        advance(iter, i - x);
        li.insert(iter, i + 1);
    }
    for(auto it = li.begin(); it != li.end(); it++){
        cout << *it << ' ';
    }   
    return 0;
}