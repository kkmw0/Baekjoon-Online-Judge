#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A, B, C;
bool visited[201][201][201];
vector<int> result;

void dfs(int a, int b, int c){
    if(visited[a][b][c]) return;

    visited[a][b][c] = true;
    if(a == 0) result.push_back(c);

    // a -> b
    if(a + b > B) dfs(a + b - B, B, c);
    else dfs(0, a + b, c);
    // a -> c
    if(a + c > C) dfs(a + c - C, b, C);
    else dfs(0, b, a + c);

    // b -> a
    if(b + a > A) dfs(A, b + a - A, c);
    else dfs(b + a, 0, c);
    // b -> c
    if(b + c > C) dfs(a, b + c - C, C);
    else dfs(a, 0, b + c);

    // c -> a
    if(c + a > A) dfs(A, b, c + a - A);
    else dfs(c + a, b, 0);
    // c -> b
    if(c + b > B) dfs(a, B, c + b - B);
    else dfs(a, c + b, 0);
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> A >> B >> C;
    dfs(0, 0, C);
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ' ';
    }
    return 0;
}