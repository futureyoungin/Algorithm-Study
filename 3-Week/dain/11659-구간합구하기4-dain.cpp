#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, M, sum = 0;
	int array[100001];
	cin >> N >> M;

	for(int i=1;i<=N;i++){
		int a;
		cin >> a;
		sum += a;
		array[i] = sum;
	}

	for(int i=0;i<M;i++){
		int start, end;
		cin >> start >> end;
		cout << array[end] - array[start-1] << "\n";
	}

}