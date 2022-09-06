#include <iostream>
#include <vector>
#define MAX_NODE 1000000

typedef long long ll;
using namespace std;

ll arr[MAX_NODE];
ll segtree[2 * MAX_NODE];
int n, m, k;

vector<ll> answer;

void init(){
    for(int i = 0; i < n; i++){
        segtree[i + n] = arr[i];
    }

    for(int i = n - 1; i != 0; i--){
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}

void update(ll i, ll x){
    segtree[i += n] = x;
    while(i >>= 1){
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}

ll query(ll l, ll r){
    ll result = 0;
    for(l += n, r += n; l != r; l >>= 1, r >>= 1){
        if(l & 1) result += segtree[l++];
        if(r & 1) result += segtree[--r];
    }
    return result;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    init();
    for(int i = 0; i < m + k; i++){
        ll a, b, c;
        cin >> a >> b >> c;

        if(a == 1){
            update(b - 1, c);
        }
        else{
            ll result = query(b - 1, c);
            answer.push_back(result);
        }
    }
    int len = answer.size();
    for(int i = 0; i < len; i++){
        cout << answer[i] << '\n';
    }
    return 0;
}