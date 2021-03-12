#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while(T--){
		int N; cin >> N;
		bool flag = true;
		string temp;
		vector<string> v;
		for(int i=0;i<N;i++){
			cin >> temp;
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		for (int i = 0; i<N-1; i++) {
			string now = v[i];
			string next = v[i+1];
			if (now.size() >= next.size()) continue;
			if (next.substr(0, now.size()) == now) {
				cout << "NO\n";
				flag = false;
				break;
			}
		}

		if(flag) cout << "YES\n";
	}

	return 0;
}