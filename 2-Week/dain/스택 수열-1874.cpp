#include <iostream>
#include <vector>

using namespace std;

//O(N^2)

int main(){
	int N, p=0, q=0;
	vector<int> stack, numbers;
	vector<char> pushpop;
	cin >> N;

	for(int i=0;i<N;i++){
		int a;
		cin >> a;
		numbers.push_back(a);
	}

	vector<int>::iterator it;
	it = numbers.begin();
	for(int i=1;i<=N;i++){
		stack.push_back(i);
		pushpop.push_back('+');
		while(!stack.empty()){
			if(*it ==stack.back()){
				stack.pop_back();
				pushpop.push_back('-');
				it++;
			}
			else	break;
		}
	}

	if(stack.empty()){
		for(int i=0;i<pushpop.size();i++){
			cout << pushpop[i] <<"\n";
		}
	}else cout << "NO\n";


}