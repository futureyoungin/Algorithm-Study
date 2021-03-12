#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first==b.first) return a.second<b.second;
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; 
	vector<pair<int, int>> v;
	cin >> N;
	for(int i=0;i<N;i++){
		int start, end;
		cin >> start >> end;
		v.push_back({start, end});
	}

	sort(v.begin(), v.end(), compare);

	vector<pair<int, int>> room;

	for(int i=0;i<v.size();i++){
		int k = 0;
		for(k = 0; k < room.size(); k++){
			if(v[i].first >= room[k].first && v[i].first < room[k].second)
				//room[k]의 사이에 있으면
				continue;
			else{
				//room[k]의 사이에 없고 end 값을 새로 갱신
				room[k].second = v[i].second;
				break;
			}
		}
		if(k ==  room.size())
			room.push_back(v[i]);
    }
    
	cout << room.size() << "\n";

	return 0;
}