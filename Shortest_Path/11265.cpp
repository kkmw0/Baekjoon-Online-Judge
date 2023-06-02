#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int graph[501][501];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }

    for(int k = 1; k <= n; k++){
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    for(int i = 0; i < m; i++){
        int a, b, t;
        cin >> a >> b >> t;
        if(graph[a][b] <= t) cout << "Enjoy other party\n";
        else cout << "Stay here\n";
    }

    return 0;
}