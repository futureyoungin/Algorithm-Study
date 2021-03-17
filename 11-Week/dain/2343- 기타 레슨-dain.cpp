#include <iostream>

using namespace std;

int N, M;
int arr[100001];

bool check(int mid){
	int sum = 0, cnt = 1;
	for(int i=0;i<N;i++){
		if(mid < arr[i]) return false;
		sum += arr[i];
		if(mid < sum){
			sum = arr[i];
			cnt++;
		}
	}
	if(cnt > M) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int sum = 0;
	for(int i=0;i<N;i++){
		cin >> arr[i];
		sum += arr[i];
	}

	int low = 1, high = sum, answer = 0;

	while(low<=high){
		int mid = (low+high)/2;
		if(check(mid)==true){
			answer = mid;
			high = mid - 1;
		}else
			low = mid+1;
	}

	cout << answer << "\n";

	return 0;
}