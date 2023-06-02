#include <iostream>

using namespace std;

int n, m, result = -1;
int board[500][500];

void tetromino_1(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 3; j++){
            int s = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
            if(s > result) result = s;
        }
    }

    for(int i = 0; i < n - 3; i++){
        for(int j = 0; j < m; j++){
            int s = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
            if(s > result) result = s;
        }
    }
}

void tetromino_2(){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            int s = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
            if(s > result) result = s;
        }
    }   
}

void tetromino_3(){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 2; j++){
            int s = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
            if(s > result) result = s;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m - 2; j++){
            int s = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 2];
            if(s > result) result = s;
        }
    }

    for(int i = 0; i < n - 2; i++){
        for(int j = 0; j < m - 1; j++){
            int s = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
            if(s > result) result = s;
        }
    } 
    for(int i = 0; i < n - 2; i++){
        for(int j = 1; j < m; j++){
            int s = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j - 1];
            if(s > result) result = s;
        }
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 2; j < m; j++){
            int s = board[i][j] + board[i][j - 1] + board[i][j - 2] + board[i + 1][j - 2];
            if(s > result) result = s;
        }
    } 
    for(int i = 1; i < n; i++){
        for(int j = 2; j < m; j++){
            int s = board[i][j] + board[i][j - 1] + board[i][j - 2] + board[i - 1][j - 2];
            if(s > result) result = s;
        }
    }

    for(int i = 2; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            int s = board[i][j] + board[i - 1][j] + board[i - 2][j] + board[i - 2][j + 1];
            if(s > result) result = s;
        }
    } 
    for(int i = 2; i < n; i++){
        for(int j = 1; j < m; j++){
            int s = board[i][j] + board[i - 1][j] + board[i - 2][j] + board[i - 2][j - 1];
            if(s > result) result = s;
        }
    }
}

void tetromino_4(){
    for(int i = 0; i < n - 2; i++){
        for(int j = 1; j < m; j++){
            int s = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 2][j - 1];
            if(s > result) result = s;
        }
    }
    for(int i = 0; i < n - 2; i++){
        for(int j = 0; j < m - 1; j++){
            int s = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1];
            if(s > result) result = s;
        }
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 2; j++){
            int s = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
            if(s > result) result = s;
        }
    } 
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m - 2; j++){
            int s = board[i][j] + board[i][j + 1] + board[i - 1][j + 1] + board[i - 1][j + 2];
            if(s > result) result = s;
        }
    }    
}

void tetromino_5(){
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            int s = board[i][j] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1];
            if(s > result) result = s;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m - 1; j++){
            int s = board[i][j] + board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1];
            if(s > result) result = s;
        }
    }

    for(int i = 1; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            int s = board[i][j] + board[i - 1][j + 1] + board[i][j + 1] + board[i + 1][j + 1];
            if(s > result) result = s;
        }
    } 
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m; j++){
            int s = board[i][j] + board[i - 1][j - 1] + board[i][j - 1] + board[i + 1][j - 1];
            if(s > result) result = s;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    tetromino_1();  // ㅡ
    tetromino_2();  // ㅁ
    tetromino_3();  // L
    tetromino_4();  // ㄹ
    tetromino_5();  // ㅗ

    cout << result << '\n';
    return 0;
}