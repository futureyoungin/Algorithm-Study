#include <iostream>
#include <queue>

using namespace std;

struct compare{
	bool operator()(int &x, int &y){
		if(abs(x)==abs(y)) return x>y;
		return abs(x) > abs(y);
	}
};

int main(){
	priority_queue<int, vector<int>, compare> pq;
	int N, t, print; cin >> N;

	for(int i=0;i<N;i++){
		scanf("%d", &t);
		if(t==0){
			if(pq.empty()) printf("%d\n", 0);
			else{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}else	pq.push(t);
	}

	return 0;
}