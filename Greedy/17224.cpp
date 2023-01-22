#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, k;
vector<pair<int, int>> v;

void solve_1(){
    for(int i = 0; i < n; i++){
        int sub1, sub2;
        cin >> sub1 >> sub2;
        v.push_back({sub2, sub1});
    }
    sort(v.begin(), v.end());

    int score = 0;
    for(int i = 0; i < n; i++){
        if(k == 0) break;
        int hard = v[i].first;

        if(hard <= l){
            score += 140;
            k--;
        }
        else{
            int easy = v[i].second;
            if(easy <= l){
                score += 100;
                k--;
            }
            else continue;
        }
    }
    cout << score << '\n';
}

void solve_2(){
    int sub1, sub2;
    int hard = 0, easy = 0;
    for(int i = 0; i < n; i++){
        cin >> sub1 >> sub2;
        if(sub2 <= l) hard++;
        else if(sub1 <= l) easy++;
    }
    cout << (k <= hard ? 140 * k : (140 * hard + 100 * min(k - hard, easy))) << '\n';
}

int main(void){
    cin >> n >> l >> k;
    //solve_1();
    solve_2();
    return 0;
}