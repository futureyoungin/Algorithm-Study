#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

//O(N)

vector<string> array_to_vector(string s){
	s = s.substr(1, s.size()-2);
	istringstream ss(s);
	string stringBuffer;
	vector<string> v;

	while(getline(ss, stringBuffer, ',')){
		v.push_back(stringBuffer);
	}

	return v;
}

void print_vector(vector<string> v, int flag, int start, int end){
	if(start>end) {
		printf("error\n");
		return;
	}

	if(start==end){
		printf("[]\n");	
		return;
	}

	if (flag==0){
		cout << "[" << v[start];
			for(int j=start+1;j<end;j++){
				cout << "," << v[j];
			}
		printf("]\n");
	}
	else{
		cout << "[" << v[end-1];
			for(int j=end-2;j>=start;j--){
				cout << "," << v[j];
			}
		printf("]\n");
	}
}

int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		string p, array;
		int n;
		cin >> p >> n >> array;
		vector<string> v = array_to_vector(array);
		int start = 0, end = v.size(), flag = 0;

		for(int j=0;j<p.size();j++){
			if(p[j] == 'R'){
				flag = (flag+1)%2;
			}
			else{
				if(start>end) break;
				if(flag==0)
					start++;
				else end--;
			}
		}

		print_vector(v, flag, start, end);

	}

	return 0;
}