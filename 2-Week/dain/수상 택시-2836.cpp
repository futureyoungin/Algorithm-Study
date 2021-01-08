#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//O(N)

bool comp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	long long N, M, src, dest, dist = 0;
	vector<pair<int, int>> location;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> src >> dest;
		if(src > dest)
			location.push_back(make_pair(src, dest));
	}

	sort(location.begin(), location.end(), comp);

	int first = location[0].first, second = location[0].second;

	//#경우1: 완전 합류 #경우2: 중간 합류 #경우3: 합류하지 않음
	for(int i=1;i<location.size();i++){
		if(first < location[i].second) {//경우3: 합류하지 않음
			dist += first - second;
			first = location[i].first; second = location[i].second;
		}else{
			first = max(first, location[i].first);
			second = min(second, location[i].second);
		}
	}

	dist += first - second;

	cout << dist*2 + M << "\n";
}