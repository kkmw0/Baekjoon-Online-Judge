#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const constexpr int M = 26;
const constexpr char OFFSET = 'a';

struct TrieNode{
    int child[M];
    bool is_Terminal;

    TrieNode(){
        is_Terminal = false;
        memset(child, -1, sizeof(int) * M);
    }
};

vector<TrieNode> nodes;

void init(){
    nodes.resize(1);
    nodes[0] = TrieNode();
}

void insert(const string& str){
    int node_id = 0;
    for(const auto& c : str){
        if(nodes[node_id].child[c - OFFSET] == -1){
            nodes[node_id].child[c - OFFSET] = nodes.size();
            nodes.emplace_back();
        }
        node_id = nodes[node_id].child[c - OFFSET];
    } 
    nodes[node_id].is_Terminal = true;
}

bool find(const string& str){
    int node_id = 0;
    for(const auto& c : str){
        if(nodes[node_id].child[c - OFFSET] == -1){
            return false;
        }
        node_id = nodes[node_id].child[c - OFFSET];
    }
    return nodes[node_id].is_Terminal;
}

int n, m;
string str;

int main(void){
    init();

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        insert(str);
    }

    int cnt = 0;
    for(int i = 0; i < m; i++){
        cin >> str;
        if(find(str) == true) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}