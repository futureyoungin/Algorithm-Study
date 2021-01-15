#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];
string dp2[1001][1001];
string string1, string2;

int main(){
	cin >> string1 >> string2;

	for(int i = 1; i<=string1.size();i++){
		for(int j = 1;j<=string2.size();j++){
			if(string1[i-1]==string2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
				dp2[i][j] = dp2[i-1][j-1] + string1[i-1];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				if(dp2[i-1][j].length() > dp2[i][j-1].length()){
					dp2[i][j] = dp2[i-1][j];
				}else{	
					dp2[i][j] = dp2[i][j-1];
				}
			}
		}
	}

	cout << dp[string1.size()][string2.size()] << "\n";
	cout << dp2[string1.size()][string2.size()] << "\n";
}