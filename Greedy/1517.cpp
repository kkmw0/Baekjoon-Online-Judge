#include <iostream>
#include <queue>

using namespace std;

int n, result, dasom;
priority_queue<int> pq;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> dasom;
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while(!pq.empty() && dasom <= pq.top()){
        int now_value = pq.top();
        pq.pop();

        dasom += 1;
        result++;
        now_value--;
        pq.push(now_value);
    }
    cout << result << '\n';
    return 0;
}