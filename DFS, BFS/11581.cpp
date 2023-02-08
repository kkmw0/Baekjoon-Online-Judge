#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, m;
int graph[101][101];

int main(void){
    cin >> n;
    for(int i = 0; i < 101; i++) fill(graph[i], graph[i] + 101, INF);
    for(int i = 1; i < n; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            int c;
            cin >> c;
            graph[i][c] = 1;
        }
    }

    for(int k = 1; k <= n; k++){
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(graph[i][i] < INF && graph[1][i] < INF){
            cout << "CYCLE" << '\n';
            return 0;
        }
    }
    cout << "NO CYCLE" << '\n';
    return 0;
}