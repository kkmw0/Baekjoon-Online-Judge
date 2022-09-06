#include <iostream>
#include <algorithm>
#include <vector>

#define parent (i >> 1)
#define left (i << 1)
#define right (i << 1 | 1)

using namespace std;

int maxHeap[100005], minHeap[100005];
int maxHeap_size, minHeap_size;
int n, x;

vector<int> ans;

void push_max(int x){
    maxHeap[++maxHeap_size] = x;
    for(int i = maxHeap_size; parent != 0 && maxHeap[parent] < maxHeap[i]; i >>= 1){
        swap(maxHeap[parent], maxHeap[i]);
    }
}

void push_min(int x){
    minHeap[++minHeap_size] = x;
    for(int i = minHeap_size; parent != 0 && minHeap[parent] > minHeap[i]; i >>= 1){
        swap(minHeap[parent], minHeap[i]);
    }
}

int pop_max(){
    int result = maxHeap[1];
    maxHeap[1] = maxHeap[maxHeap_size--];

    for(int i = 1; left <= maxHeap_size;){
        int max_child = left == maxHeap_size || maxHeap[left] > maxHeap[right] ? left : right;
        if(maxHeap[max_child] > maxHeap[i]){
            swap(maxHeap[max_child], maxHeap[i]);
            i = max_child;
        }
        else break;
    }
    return result;
}

int pop_min(){
    int result = minHeap[1];
    minHeap[1] = minHeap[minHeap_size--];

    for(int i = 1; left <= minHeap_size;){
        int min_child = left == minHeap_size || minHeap[left] < minHeap[right] ? left : right;
        if(minHeap[min_child] < minHeap[i]){
            swap(minHeap[min_child], minHeap[i]);
            i = min_child;
        }
        else break;
    }
    return result;
}

int main(){
    cin >> n;

    cin >> x;
    push_max(x);
    ans.push_back(maxHeap[1]);

    for(int i = 0; i < n - 1; i++){
        int a;
        cin >> a;

        if(a > maxHeap[1]) push_min(a);
        else push_max(a);

        if(minHeap_size > maxHeap_size){
            push_max(pop_min());
        }
        else if(maxHeap_size - 1 > minHeap_size){
            push_min(pop_max());
        }
        ans.push_back(maxHeap[1]);
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
    return 0;
}