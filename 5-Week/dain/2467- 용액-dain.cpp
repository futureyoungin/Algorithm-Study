#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	int N, temp;
	vector<int> chemical;

	cin >> N;

	for(int i=0;i<N;i++){
		cin >> temp;
		chemical.push_back(temp);
	}

	int left = 0, right = N-1 , abs_min = 2147483647;
	int save_left = left, save_right = right;

	while(left<right){
		int chm = chemical[left]+chemical[right];
		if(abs(chm) < abs_min){
			abs_min = abs(chm);
			save_left = left; save_right = right;
		}
		if(chm < 0){
			left++;
		}else{
			right--;
		}
	}

	cout << chemical[save_left] << " " << chemical[save_right] << "\n";

	return 0;
}