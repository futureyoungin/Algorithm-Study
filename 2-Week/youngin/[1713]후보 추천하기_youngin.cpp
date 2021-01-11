#include <iostream>

using namespace std;

#define MAX_STUDENT 100
#define INSERT 0			// 액자에 사람이 적은 경우
#define NO_ERASE -1			// 이미 액자에 걸려 있는 경우.

#define ON 0
#define RECOMMEND 1
#define TIME 2

// 액자에 걸릴 수 있는 최대 수.
int prize;
int n_recommend;
int students[3][MAX_STUDENT + 1] = { 0, }; // [0]-> On the prize / [1]-> 득표 수 / [2]-> 타임.





void input() {
	cin >> prize;
	cin >> n_recommend;
}

int select_target(int new_student) {
	int target = 1;
	int min_score = 10000;
	int old = 10000;
	int on_prize_students = 0;
	for (int i = 1; i <= MAX_STUDENT; i++) {
		if (students[ON][i]) {
			if (i != new_student) {
				on_prize_students++;
			}
			else if (i == new_student) {
				return NO_ERASE;		// no earse target.
			}

			if (students[RECOMMEND][i] < min_score) {
				min_score = students[RECOMMEND][i];
				target = i;
				old = students[TIME][i];
			}
			else if (students[RECOMMEND][i] == min_score) {
				if (students[TIME][i] < old) {
					old = students[TIME][i];
					target = i;
				}
			}
		}
	}
	if (on_prize_students < prize) {
		return INSERT; // no earse target
	}
	return target;
}

void earse_target(int student) {
	students[ON][student] = 0;
	students[RECOMMEND][student] = 0;
	students[TIME][student] = 0;
}

void insert_student(int student, int time) {
	students[ON][student] = 1;
	students[RECOMMEND][student] = 1;
	students[TIME][student] = time;
}

void op() {
	int student;
	for (int i = 0; i < n_recommend; i++) {
		cin >> student;
		int target = select_target(student);
		if (target == INSERT) {
			insert_student(student, i);
		}
		else if (target == NO_ERASE) {
			students[RECOMMEND][student]++;
		}
		else {
			earse_target(target);
			insert_student(student, i);
		}
	}
}

void print_result() {
	for (int i = 1; i <= MAX_STUDENT; i++) {
		if (students[ON][i]) {
			cout << i << " ";
		}
	}
}



int main() {
	input();
	op();
	print_result();
	return 0;
}