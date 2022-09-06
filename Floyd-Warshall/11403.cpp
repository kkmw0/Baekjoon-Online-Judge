#include <iostream>
#define INF 1e9

using namespace std;

int graph[100][100];
int n;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 0) graph[i][j] = INF;
        }
    }

    for(int k = 0; k < n; k++){
        for(int a = 0; a < n; a++){
            for(int b = 0; b < n; b++){
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            if(graph[a][b] == INF) cout << 0 << ' ';
            else cout << 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}