#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	/// --- 시간 초과 ---
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/// --- 시간 초과 ---

	int N, line_size = 0;
	vector<pair<int, int>> line;
	cin >> N;

	for(int i=0;i<N;i++){
		int start, end;
		cin >> start >> end;
		line.push_back(make_pair(start, end));
	}

	sort(line.begin(), line.end());
	int start = line[0].first, end = line[0].second;

	for(int i=1;i<N;i++){
		if(line[i].first > end){
			line_size += end - start;
			start = line[i].first; end = line[i].second;
		}else{
			end = max(end, line[i].second);
		}
	}

	line_size += end - start;

	cout << line_size << "\n";
}