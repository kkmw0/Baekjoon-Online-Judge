#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> cow[100];

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;

}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> cow[i].first >> cow[i].second;
    sort(cow, cow + n, cmp);

    long long result = 0, now_time = 0;
    for(int i = 0; i < n; i++){
        if(cow[i].first > now_time){
            result += cow[i].first - now_time;
            now_time = cow[i].first;
        }
        result += cow[i].second;
        now_time += cow[i].second;
    }
    cout << result << '\n';
    return 0;
}