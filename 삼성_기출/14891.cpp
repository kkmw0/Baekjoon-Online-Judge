#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Gear{
    char left, right;
};

int k, result;
int score[5] = {0, 1, 2, 4, 8};
bool flag[5][2]; //시계방향, 반 시계방향
vector<char> v[5];
Gear gear[5];

void get_value(){
    for(int i = 1; i <= 4; i++){
        for(int j = 0; j < 8; j++){
            if(j == 2) gear[i].right = v[i][j];
            else if(j == 6) gear[i].left = v[i][j];
        }
    }
}

void spin(int num, int d){
    for(int i = 1; i <= 4; i++){
        for(int j = 0; j < 2; j++){
            flag[i][j] = false;
        }
    }

    if(num == 1){
        if(gear[1].right != gear[2].left){
            if(d == 1) flag[2][1] = true;
            else flag[2][0] = true;
        }
        if((gear[2].right != gear[3].left) && (flag[2][0] || flag[2][1])){
            if(flag[2][0]) flag[3][1] = true;
            else flag[3][0] = true;
        }
        if((gear[3].right != gear[4].left) && (flag[3][0] || flag[3][1])){
            if(flag[3][0]) flag[4][1] = true;
            else flag[4][0] = true;
        }
    }
    else if(num == 2){
        if(gear[1].right != gear[2].left){
            if(d == 1) flag[1][1] = true;
            else flag[1][0] = true;
        }
        if(gear[2].right != gear[3].left){
            if(d == 1) flag[3][1] = true;
            else flag[3][0] = true;
        }
        if((gear[3].right != gear[4].left) && (flag[3][0] || flag[3][1])){
            if(flag[3][0]) flag[4][1] = true;
            else flag[4][0] = true;
        }
    }
    else if(num == 3){
        if(gear[3].right != gear[4].left){
            if(d == 1) flag[4][1] = true;
            else flag[4][0] = true;
        }
        if(gear[2].right != gear[3].left){
            if(d == 1) flag[2][1] = true;
            else flag[2][0] = true;
        }
        if((gear[1].right != gear[2].left) && (flag[2][0] || flag[2][1])){
            if(flag[2][0]) flag[1][1] = true;
            else flag[1][0] = true;
        }
    }
    else{
        if(gear[3].right != gear[4].left){
            if(d == 1) flag[3][1] = true;
            else flag[3][0] = true;
        }
        if((gear[2].right != gear[3].left) && (flag[3][0] || flag[3][1])){
            if(flag[3][0]) flag[2][1] = true;
            else flag[2][0] = true;
        }
        if((gear[1].right != gear[2].left) && (flag[2][0] || flag[2][1])){
            if(flag[2][0]) flag[1][1] = true;
            else flag[1][0] = true;
        }
    }
    for(int i = 1; i <= 4; i++){
        if(i == num) continue;
        if(flag[i][0]) rotate(v[i].begin(), v[i].end() - 1, v[i].end());
        else if(flag[i][1]) rotate(v[i].begin(), v[i].begin() + 1, v[i].end());
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 4; i++){
        string str; cin >> str;
        for(int j = 0; j < 8; j++){
            char now = str[j];
            v[i].push_back(now);
        }
    }

    cin >> k;
    for(int i = 0; i < k; i++){
        int num, d;
        cin >> num >> d;
        get_value();

        if(d == 1){
            spin(num, d);
            rotate(v[num].begin(), v[num].end() - 1, v[num].end());
        }
        else{
            spin(num, d);
            rotate(v[num].begin(), v[num].begin() + 1, v[num].end());
        }
    }

    for(int i = 1; i <= 4; i++){
        if(v[i][0] == '1') result += score[i];
    }
    cout << result << '\n';
    return 0;
}