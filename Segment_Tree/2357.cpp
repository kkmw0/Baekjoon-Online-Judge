#include <iostream>
#include <algorithm>
#define MAX_NODE 100000

using namespace std;

int arr[MAX_NODE];
int minSegtree[MAX_NODE * 4];
int maxSegtree[MAX_NODE * 4];
int n, m, _size;

void init(){
    for(_size = 1; _size < n; _size *= 2) {}

    int idx = 0;
    for(int i = _size; i < _size + n; i++){
        minSegtree[i] = arr[idx];
        maxSegtree[i] = arr[idx];
        idx++;
    }

    for(int i = _size + n; i < _size * 2; i++){
        minSegtree[i] = 1e9 + 1;
        maxSegtree[i] = -1;
    }

    for(int i = _size - 1; i != 0; i--){
        minSegtree[i] = min(minSegtree[i << 1], minSegtree[i << 1 | 1]);
        maxSegtree[i] = max(maxSegtree[i << 1], maxSegtree[i << 1 | 1]);
    }
}

pair<int, int> query(int l, int r){
    int minValue = 1e9 + 1;
    int maxValue = -1;

    for(l += _size, r += _size; l != r; l >>= 1, r >>= 1){
        if(l & 1){
            minValue = min(minValue, minSegtree[l]);
            maxValue = max(maxValue, maxSegtree[l]);            
            l++;
        }
        if(r & 1){
            r--;
            minValue = min(minValue, minSegtree[r]);
            maxValue = max(maxValue, maxSegtree[r]);            
        }
    }
    return make_pair(minValue, maxValue);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    init();
    for(int i = 0; i < m; i++){
        int left, right;
        cin >> left >> right;
        pair<int, int> result = query(left - 1, right);
        cout << result.first << ' ' << result.second << '\n';
    }
    return 0;
}