#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N;
		cin >> N;
		int count = 0;
		pair<int, int> arr[N];
		for(int j=0;j<N;j++){
			cin >> arr[j].first >> arr[j].second;
		}
		sort(arr, arr+N);
		int min = N;
		for(int j=0;j<N;j++){
			if (j == 0) {count++; min = arr[j].second;}
			else{
				if (arr[j].second < min){
					count ++;
					min = arr[j].second;
				}
			}
		}
		cout << count << "\n";
	}	
}