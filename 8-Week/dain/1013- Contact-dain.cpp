#include <iostream>
#include <string>

using namespace std;

int state_table[10][2] = {
	{0, 0},
	{6, 2},
	{3, -1},
	{4, -1},
	{4, 5},
	{6, 9},
	{-1, 7},
	{6, 2},
	{4, 7},
	{8, 9}
};

string check_wave(string wave){
	int state = 1;
	for(int i=0;i<wave.size();i++){
		state = state_table[state][wave[i]-'0'];
		if(state==-1) return "NO";
	}
	if(state == 5 || state == 7 || state == 9) return "YES";
	return "NO";
}

int main(){
	int T; cin >> T;
	while(T--){
		string wave;
		cin >> wave;
		cout << check_wave(wave) <<"\n";
	}
	return 0;
}