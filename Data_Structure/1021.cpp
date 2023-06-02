#include <iostream>
#include <deque>

using namespace std;

int n, m, front, back, result;
deque<int> dq;

// deque에서 제거할 원소의 인덱스를 앞과 뒤에서 부터 확인하여 count
void get_count(int x){
    for(auto it = dq.begin(); it != dq.end(); it++){
        if(x == *it) break;
        front++;
    }
    for(auto it = dq.end() - 1; it != dq.begin() - 1; it--){
        if(x == *it) break;
        back++;
    }    
}

void find_from_front(){
    while(front--){
        int now = dq.front();
        dq.pop_front();
        dq.push_back(now);
        result++;
    }
}

void find_from_back(){
    while(back--){
        int now = dq.back();
        dq.pop_back();
        dq.push_front(now);
        result++;
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) dq.push_back(i);

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;

        if(x != dq.front()){
            front = 0, back = 1;
            get_count(x);   // 앞에서 찾을 때와, 뒤에서 찾을 때 얼마나 걸리는지 확인
            if(front < back) find_from_front(); // 뒤에서 부터 찾는 것이 빠른경우
            else find_from_back();  // 앞에서 부터 찾는 것이 빠른경우
        }
        dq.pop_front();
    }
    cout << result << '\n';
    return 0;
}