#include <iostream>
#include <vector>

using namespace std;

int max_, min_;

void calculate(int num, vector<int> numbers, vector<int> math_sign, int target, int total){
	if (math_sign[target] == 0 && total != 0)
		return;
	if(numbers.empty() && total == 0){
		max_ = max(max_, num);
		min_ = min(min_, num);
		return;
	}
	
	int front = numbers.front();	numbers.erase(numbers.begin());
	math_sign[target]--; total--;

	switch(target){
		case 0:
			num += front;
			break;
		case 1:
			num -= front;
			break;
		case 2:
			num *= front;
			break;
		case 3:
			num /= front;
			break;
	}

	for(int i=0;i<4;i++){
		calculate(num, numbers, math_sign, i, total);
	}
}

int main(){
	int N, total = 0;
	min_ = 1000000000, max_ = -1000000000;
	vector<int> numbers;
	vector<int> math_sign;

	cin >> N;

	for(int i=0;i<N;i++){
		int temp = 0;
		cin >> temp;
		numbers.push_back(temp);
	}

	for(int i=0;i<4;i++){
		int temp = 0;
		cin >> temp;
		total += temp;
		math_sign.push_back(temp);
	}

	int front = numbers.front();
	numbers.erase(numbers.begin());

	for(int i=0;i<4;i++){
		calculate(front, numbers, math_sign, i, total);
	}

	cout << max_ << "\n";
	cout << min_ << "\n";
}