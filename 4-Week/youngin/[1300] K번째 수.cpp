#include <iostream>
#include <algorithm>

using namespace std;
int n, k;

int bin_search(){
    int left = 1, right = k;
    int mid;
    int cnt;
    int result=-1;
    while(left <= right){
        cnt=0;
        mid = (left+right)/2;
        for(int i=1; i<=n; i++){
            cnt += min(mid/i, n);
        }
        if(cnt < k)
            left = mid + 1;
        else{
            right = mid - 1;
            result = mid;
        }
    }
    return result;
}


int main(){
    cin >> n >> k;    
    cout << bin_search();
    return 0;
}