#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (maxHeap.size() > minHeap.size()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        if (!minHeap.empty() && !maxHeap.empty() && maxHeap.top() > minHeap.top()) {
            int a = minHeap.top(), b = maxHeap.top();
            minHeap.pop(), maxHeap.pop();
            minHeap.push(b), maxHeap.push(a);
        }
        cout << maxHeap.top() << '\n';
    }
    return 0;
}