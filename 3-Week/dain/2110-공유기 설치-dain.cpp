#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	cin.sync_with_stdio(false);
    cin.tie(NULL);
    
	int N, C, a, answer = -1;
	cin >> N >> C;
	int wifi[200001] = {0,};

	for(int i=0;i<N;i++){
		cin >> wifi[i];
	}

	sort(wifi, wifi+N);

	int left = 0, right = wifi[N-1];

	while(left<=right){
		int mid = (left+right)/2;
		int prev = 0, cnt = 1;
		for(int i=1;i<N;i++){
			if(wifi[i] - wifi[prev] >= mid){
				prev = i;
				cnt++;
			}
		}

		if(cnt >= C){
			left = mid+1;
			answer = mid;
		}else right = mid-1;
	}

	cout << answer << "\n";

}	