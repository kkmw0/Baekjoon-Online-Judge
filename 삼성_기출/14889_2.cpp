#include <iostream>
#include <algorithm>

using namespace std;

int n, result = 1e9;
int arr[20][20];
int team1[10], team2[10];
int pick[20];

void update(){
    int team1_size = 0, team2_size = 0;
    for(int i = 0; i < n; i++){
        if(pick[i] == 0) team1[team1_size++] = i;
        else team2[team2_size++] = i;
    }
    int team1_s = 0, team2_s = 0;
    for(int i = 0; i < n / 2; i++){
        for(int j = i + 1; j < n / 2; j++){
            team1_s += arr[team1[i]][team1[j]] + arr[team1[j]][team1[i]];
            team2_s += arr[team2[i]][team2[j]] + arr[team2[j]][team2[i]];
        }
    }
    result = min(result, abs(team1_s - team2_s));
}

void dfs(int now, int cnt){
    if(cnt == n / 2){
        update();
        return;
    }
    for(int i = now; i < n; i++){
        pick[i] = 1;
        dfs(i + 1, cnt + 1);
        pick[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);
    cout << result << '\n';
    return 0;
}