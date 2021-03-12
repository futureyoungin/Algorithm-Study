#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_mid(vector<int> v){
	if(v.size() % 2 == 1){
		return v[v.size() / 2];
	}else{
		return (v[v.size()/2] + v[v.size()/2 - 1]) / 2;
	}
}

int get_distance(vector<int> v, int x){
	int sum = 0;
	for(int i=0;i<v.size();i++){
		sum += abs(x - v[i]);
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, a, b; 
	cin >> N >> M;

	vector<int> x, y;	

	for(int i=0;i<M;i++){
		cin >> a >> b;
		x.push_back(a); y.push_back(b);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int mid_x = get_mid(x);
	int mid_y = get_mid(y);

	int answer = get_distance(x, mid_x) + get_distance(y, mid_y);

	cout << answer << "\n";

	return 0;
}