#include <iostream>
#include <cstring>

using namespace std;

#define MAX_VALUE 100010
#define POP "-"
#define PUSH "+"

int n;
int stack_element[MAX_VALUE] = {0,};
int element[MAX_VALUE] = {0,};
int possible = true;

void input(){
	int temp_element, before_element = 0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> temp_element;
		if(temp_element < before_element){
			for(int j=temp_element+1; j<before_element; j++){
				if(stack_element[j] != 1){
					possible = false;
					return;
				}
			}
		}
		element[i] = temp_element;
		stack_element[temp_element] = 1;
		before_element = temp_element;
	}
}

void stack(){
	memset(stack_element, 0, sizeof(int)*MAX_VALUE);
	int entrance = 0, max_stacked = 0;
	for(int i=0; i<n; i++){
		while(max_stacked <element[i]){
			stack_element[entrance++] = (++max_stacked);
			cout << PUSH << "\n";
		}
		while(stack_element[entrance] != element[i]){
			entrance--;
			cout << POP << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	if(possible == false){
		cout << "NO";
		return 0;
	}
	stack();
	
	return 0;
}