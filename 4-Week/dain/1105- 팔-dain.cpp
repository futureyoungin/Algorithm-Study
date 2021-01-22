#include <iostream>

using namespace std;

int main(){
	string L, R;
	int answer = 0;
	cin >> L >> R;

	if(L.size()==R.size()){
		for(int i=0;i<L.size();i++){
			if(L[i] == '8' && R[i]== '8')	answer++;
			if(L[i]!= R[i])					break;
		}
	}

	cout << answer << "\n";
	return 0;
}