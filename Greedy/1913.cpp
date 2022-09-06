#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, last, cnt;
vector<pair<int, int>> meetings;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        meetings.push_back({end, start});
    }
    sort(meetings.begin(), meetings.end());

    last = cnt = 0;
    for(int i = 0; i < n; i++){
        if(meetings[i].second < last) continue;
        last = meetings[i].first;
        cnt++;
    }
    
    cout << cnt << '\n';
    return 0;
}