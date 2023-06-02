#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int belt[200], robot[200000];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < 2 * n; i++) cin >> belt[i];

    int result = 0, cnt = 0;
    int front = 0, back = 0;
    while(cnt < k){
        result++;

        int tmp = belt[2 * n - 1];
        for(int i = 2 * n - 1; i > 0; i--) belt[i] = belt[i - 1];
        belt[0] = tmp;

        for(int i = front; i < back; i++){
            robot[i]++;
            if(robot[i] == n - 1) front++;
        }

        for(int i = front; i < back; i++){
            int next = robot[i] + 1;
            
            if(belt[next] == 0 || (i != front && robot[i - 1] == next)) continue;
            robot[i] = next;
            if(robot[i] == n - 1) front++;
            belt[next]--;
            if(belt[next] == 0) cnt++;
        }

        if(belt[0] > 0 && (back == 0 || robot[back - 1] != 0)){
            robot[back++] = 0;
            belt[0]--;
            if(belt[0] == 0) cnt++;
        }
    }
    cout << result << '\n';
    return 0;
}