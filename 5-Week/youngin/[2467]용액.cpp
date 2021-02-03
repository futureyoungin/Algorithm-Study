#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N;
int liquid[100000]={0, };
int min_left, min_right, min_value;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> liquid[i];
}

void two_point(){
    int idx_left = 0, idx_right = N-1, temp_min;
    min_value = abs(liquid[idx_left] + liquid[idx_right]);
    min_left = 0, min_right = N-1;
    while(idx_left < idx_right){
        temp_min = liquid[idx_left] + liquid[idx_right];
        if(temp_min == 0){
            min_left = idx_left, min_right = idx_right;
            break;
        }
        if(min_value > abs(temp_min)){
            min_value = abs(temp_min);
            min_left = idx_left, min_right = idx_right;
        }
        if(temp_min > 0)
            idx_right--;
        else
            idx_left++;
    }
}

int main(){
    input();
    two_point();
    cout << liquid[min_left] << " " << liquid[min_right];
    return 0;
}