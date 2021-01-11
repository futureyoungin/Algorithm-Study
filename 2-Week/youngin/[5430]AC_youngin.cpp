#include <iostream>
#include <string>
#include <deque>

using namespace std;

int T, n;
string command, a_data;
string temp = "";
int array_size;

deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		bool reverse = false;
		bool isError = false;
		cin >> command;
		cin >> array_size;
		cin >> a_data;

		for (int j = 0; j < a_data.length(); j++) {
			if (a_data[j] == '[') continue;
			else if (a_data[j] >= '0' && a_data[j] <= '9') {
				temp += a_data[j];
			}
			else if ((a_data[j] == ',' || a_data[j] == ']') && temp != "") {
				dq.push_back(atoi(temp.c_str()));
				temp = "";
			}
		}

		for (int j = 0; j < command.length(); j++) {
			if (command[j] == 'R')
				reverse = !reverse;
			else if (command[j] == 'D') {
				if (dq.empty()) {
					isError = true;
					break;
				}
				if (reverse) dq.pop_back();
				else dq.pop_front();
			}
		}
		if (isError) {
			cout << "error\n";
		}
		else if (dq.empty()) {
			cout << "[]\n";
		}
		else if (reverse) {
			cout << "[";
			while (dq.size() > 1) {
				cout << dq.back() << ",";
				dq.pop_back();
			}
			cout << dq.back() << "]\n";
			dq.pop_back();
		}
		else {
			cout << "[";
			while (dq.size() > 1) {
				cout << dq.front() << ",";
				dq.pop_front();
			}
			cout << dq.front() << "]\n";
			dq.pop_back();
		}
	}
	return 0;
}