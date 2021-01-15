#include <iostream>
#include <queue>

// heap -> push O(logn).

using namespace std;

int n, mid=1000001;
priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>>               max_heap;


void find_mid(){
    int temp, swap;
    for(int i=0; i<n; i++){
        cin >> temp;
        if(temp < mid)
            max_heap.push(temp);
        else
            min_heap.push(temp);
        
        if(max_heap.size() > min_heap.size()+1){
            swap = max_heap.top();
            max_heap.pop();
            min_heap.push(swap);
        }
        else if(min_heap.size() > max_heap.size() + 1 ){
            swap = min_heap.top();
            min_heap.pop();
            max_heap.push(swap);
        }
        
        if(min_heap.size() > max_heap.size())
            mid = min_heap.top();
        else
            mid = max_heap.top();
        
        cout << mid << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    find_mid();
    return 0;
}