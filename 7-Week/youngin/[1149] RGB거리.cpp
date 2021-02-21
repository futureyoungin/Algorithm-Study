#include <iostream>
#include <algorithm>

using namespace std;

int dp_rgb[1001][3]={0,};
int rgb[1001][3] ={0, };
int N;

int before_min_rgb(int cur_n, int cur_color){
    int min_weight=1000000000;
    for(int i=0; i<3; i++){
        if(i==cur_color)
            continue;
        min_weight = min(min_weight, dp_rgb[cur_n-1][i]);    
    }
    return min_weight;
}

int main()
{
    int sum_weight = 1000000000;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }
    for(int i=1; i<=N; i++){
        for(int j=0; j<3; j++){
            dp_rgb[i][j] += rgb[i][j] + before_min_rgb(i, j);
        }
    }
    for(int i=0; i<3; i++){
        
        sum_weight = min(sum_weight, dp_rgb[N][i]);
    }
    cout << sum_weight;
    
    return 0;
}