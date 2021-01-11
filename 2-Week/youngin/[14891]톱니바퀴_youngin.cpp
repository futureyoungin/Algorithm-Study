#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>

using namespace std;

#define clock 1
#define counterclock -1
#define N_GEAR 4

string gear[N_GEAR];
int k;
vector<pair<int, int>> action;

void input() {
	for (int i = 0; i < N_GEAR; i++) {
		cin >> gear[i];
	}
	cin >> k;
	int num_gear, direction;
	for (int i = 0; i < k; i++) {
		cin >> num_gear >> direction;
		action.push_back(make_pair(num_gear-1, direction));
	}
}

void rotating(int num_gear, int direction) {		 // 하나의 톱니를 회전시키기.
	if (direction == clock) {
		string temp_g = gear[num_gear].substr(7,1);
		gear[num_gear].erase(7, 1);
		gear[num_gear] = temp_g + gear[num_gear];
	}
	else if (direction == counterclock) {
		string temp_g = gear[num_gear].substr(0,1);
		gear[num_gear].erase(0, 1);
		gear[num_gear] =  gear[num_gear] + temp_g;
	}
}

void relation(int num_gear, int direction) { // 하나의 톱니를 회전시켰을 때 미치는 영향
	int left_side, right_side;
	char origin_left = gear[num_gear].at(6);
	char origin_right = gear[num_gear].at(2);
	int now_direction = direction;
	int next_direction;
	int now_gear;


	for (left_side = num_gear - 1; left_side >= 0; left_side--) { 
		now_gear = left_side + 1;
		if (gear[left_side].at(2) == origin_left) {  // 왼쪽으로 변화가 없는 경우.
			break;
		}
		else {
			next_direction = now_direction * (-1);   // 반대 방향으로 회전
		}
		origin_left = gear[left_side].at(6);
		rotating(left_side, next_direction);
		now_direction = next_direction;
	}

	now_direction = direction;

	for (right_side = num_gear + 1; right_side < N_GEAR; right_side++) {
		now_gear = right_side - 1;
		if (gear[right_side].at(6) == origin_right) {  // 오른쪽으로 변화가 없는 경우.
			break;
		}
		else {
			next_direction = now_direction * (-1);     // 반대 방향으로 회전
		}

		origin_right = gear[right_side].at(2);
		rotating(right_side, next_direction);
		now_direction = next_direction;
	}
}

void op() {
	vector<pair<int, int>>::iterator iter;
	for (iter = action.begin(); iter != action.end(); iter++) {
		relation(iter->first, iter->second);
		rotating(iter->first, iter->second);
	}
}

int print_score() {
	int score = 0;
	for (int i = 0; i < N_GEAR; i++) {
		if (gear[i].at(0) == '1') {
			score += (int)pow(2.0, i);
		}
	}
	return score;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	op();
	cout << print_score();
	return 0;
}