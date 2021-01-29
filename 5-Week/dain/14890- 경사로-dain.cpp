#include <iostream>

using namespace std;

int N, L;
int board[101][101], arr[101];

void Input(){
	cin >> N >> L;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> board[i][j];
		}
	}
}

bool check_pass(int line, int direction){
	for(int k=0;k<N;k++){
		if (direction==0)	arr[k] = board[line][k];
		else				arr[k] = board[k][line];
	}

	int temp = arr[0];

	for(int i=1;i<N;i++){
		if(arr[i] == temp) continue;		//1. 경사로 설치가 필요없음
		else if(arr[i] == -1) continue;	//2. 경사로 설치 된 구역
		else if(arr[i] - temp == 1){		//3. 경사로 설치 필요(오르막길)
			for(int j = i-1; j > i-L-1; j--){	//경사로 설치 가능 여부 확인
				if(j<0 || temp != arr[j]) return false;
				arr[j] = -1;	//경사로 설치 표시
			}
			temp = arr[i];
		}else if(temp-arr[i]==1){			//4. 경사로 설치 필요(내리막길)
			temp = arr[i];
			for(int j = i; j < i + L; j++){
				if(j>=N || temp != arr[j])	return false;
				arr[j] = -1;
			}
		}else if(temp-arr[i]>=2 || arr[i]-temp>=2){	//5. 높이 차가 2 이상 차이남
			return false;
		}
	}
	return true;
}

void Solution(){
	int answer = 0;
	for(int i=0;i<N;i++){
		answer += check_pass(i, 0);
		answer += check_pass(i, 1);
	}
	cout << answer << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	Solution();

	return 0;
}
