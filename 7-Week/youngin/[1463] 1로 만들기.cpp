#include <iostream>
#include <algorithm>

using namespace std;

int dp[3300001]={0,};
int N;

int find_min(int two_times, int three_times, int plus_one){
    int temp_array[3];
    if(two_times > N) temp_array[0] = 1000000000;
    else temp_array[0] = dp[two_times];
    
    if(three_times > N) temp_array[1] = 1000000000;
    else temp_array[1] = dp[three_times];
    
    temp_array[2] = dp[plus_one];
    
    sort(temp_array, temp_array+3);
    return temp_array[0];
}

int main(){
    cin >> N;
    for(int i=N-1; i>=1; i--){
        dp[i] = find_min(2*i, 3*i, i+1) + 1;
    }
    cout << dp[1];
    return 0;
}