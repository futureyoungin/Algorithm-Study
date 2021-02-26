#include <iostream>
#include <string>
#include <regex>

using namespace stdl

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	while(T--){
		string wave;
		cin >> wave;
		regex pattern("(100+1+|01)+");
		if(regex_match(pattern, wave)) cout << "YES\n";
		else << "NO\n";
	}
}