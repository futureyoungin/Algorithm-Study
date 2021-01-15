#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, tmp;
	priority_queue<int, vector<int>, less<int>> left_heap;
	priority_queue<int, vector<int>, greater<int>> right_heap;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> tmp;
		if(left_heap.empty()){
			left_heap.push(tmp);
		}else if(!right_heap.empty() && left_heap.size() == right_heap.size()){
			left_heap.push(tmp);
		}else{
			right_heap.push(tmp);
		}

		if(!left_heap.empty() && !right_heap.empty() && left_heap.top() > right_heap.top()){
			int left_tmp = left_heap.top();
			int  right_tmp = right_heap.top();
			left_heap.pop();
			right_heap.pop();
			left_heap.push(right_tmp);
			right_heap.push(left_tmp);
		}
		printf("%d\n", left_heap.top());
	}
}