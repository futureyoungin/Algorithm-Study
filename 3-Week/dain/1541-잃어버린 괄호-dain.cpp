#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	int answer = 0;
	bool flag = false;
	string tmp = "";

	string math;
	cin >> math;

	for(int i=0;i<=math.size();i++){
		if(math[i] == '+' || math[i] == '-' || math[i] == '\0'){
			if(flag)	answer -= stoi(tmp);
			else answer += stoi(tmp);
			if(math[i] == '-')	flag = true;
			tmp = "";
		}else{
			tmp += math[i];
		}
	}


	cout << answer << "\n";
}