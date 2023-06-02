#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;

int main(void){
    ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) q.push(i);

    cout << "<";
    while(q.size() > 1){
        for(int i = 1; i < k; i++){
            int now = q.front();
            q.pop();
            q.push(now);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">\n";
    return 0;
}