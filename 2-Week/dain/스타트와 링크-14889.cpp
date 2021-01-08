#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2147483647

using namespace std;

//O(n!*n^2)

int N;

int main(){
	int member[21][21];
	vector<int> v;
	int answer = MAX;

	cin >> N;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> member[i][j];
		}
	}

    for(int i=0;i<N/2;i++) v.push_back(0);
    for(int i=0;i<N/2;i++) v.push_back(1);

    do{
    	vector<int> start, link;
    	int start_level = 0, link_level = 0;

    	for(int i=0;i<v.size();i++){
    		if(v[i] == 0) start.push_back(i+1);	//start team
    		else link.push_back(i+1);				//link team
        }

        for(int i=0;i<N/2;i++){
        	for(int j=0;j<i;j++){
        		if(i==j) continue;
        		start_level += (member[start[i]][start[j]] + member[start[j]][start[i]]);
        		link_level += (member[link[i]][link[j]] + member[link[j]][link[i]]);
        	}
        }
        answer = min(answer, abs(start_level-link_level));

    }while(next_permutation(v.begin(), v.end()));

    cout << answer << "\n";

}