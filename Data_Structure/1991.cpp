#include <iostream>

using namespace std;

int n;
pair<char, char> node[26];

void pre_order(char x){
    if(x == '.') return;
    cout << x;
    pre_order(node[x - 'A'].first);
    pre_order(node[x - 'A'].second);
}

void in_order(char x){
    if(x == '.') return;
    in_order(node[x - 'A'].first);
    cout << x;
    in_order(node[x - 'A'].second);
}

void post_order(char x){
    if(x == '.') return;
    post_order(node[x - 'A'].first);
    post_order(node[x - 'A'].second);
    cout << x;
}

void search_tree(char x){
    pre_order(x); cout << '\n';
    in_order(x); cout << '\n';
    post_order(x); cout << '\n';
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        char a, l, r;
        cin >> a >> l >> r;
        node[a - 'A'] = {l, r};
    }
    search_tree('A');
    return 0;
}