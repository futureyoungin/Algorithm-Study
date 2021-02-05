#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	int line_count = 0;

	while(cin>>input){
		if(input=="<hr>") {
			if(line_count != 0) cout << "\n";
			for(int i=0;i<80;i++){
				cout << "-";
			}
			cout << "\n";
			line_count = 0;
		}else if(input=="<br>"){
			cout << "\n";
			line_count = 0;
		}else{
			if(input.size()+line_count >= 80){
				cout << "\n";
				line_count = 0;
			}
			if(line_count != 0){
				line_count += input.size() + 1;
				cout << " " << input;
			}else{
				line_count += input.size();
				cout << input;
			}
		}
	}
	return 0;
}