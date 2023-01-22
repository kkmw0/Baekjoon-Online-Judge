#include <iostream>
#include <vector>

using namespace std;

long long n, x, result, min_cost, idx;
vector<long long> dist, cost;

int main(void){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> x;
        dist.push_back(x);
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        cost.push_back(x);
    }

    min_cost = cost[0];
    result = cost[0] * dist[0];
    for(int i = 1; i < n - 1; i++){
        if(cost[i] < min_cost){
            min_cost = cost[i];
            idx = i;
        }
        result += cost[idx] * dist[i];
    }
    cout << result << '\n';
    return 0;
}