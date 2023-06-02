#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Value{
    int cnt, idx, value;
};

int n, c;
vector<Value> v;

bool cmp(Value a, Value b){
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    else return a.idx < b.idx;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        int x; cin >> x;

        bool flag = false;
        for(int idx = 0; idx < v.size(); idx++){
            if(v[idx].value == x){
                v[idx].cnt++;
                flag = true;
                break;
            }
        }
        if(!flag) v.push_back({1, i, x});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].cnt; j++){
            cout << v[i].value << ' ';
        }
    }
    return 0;
}