#include <stdio.h>
#include <algorithm>

using namespace std;

int N,M,i,idx=0;
long long ans;
pair<int,int> arr[300000];

void drive(){
    int start_i = arr[0].first;
    int end_i = arr[0].second;
    for(i=1; i<idx; i++){
        if( arr[i].first>end_i ){
            ans += (end_i-start_i)*2;
            start_i = arr[i].first;
            end_i = arr[i].second;
        }else{
            if( arr[i].second>end_i ) end_i = arr[i].second;
        }
    }
    ans += (end_i-start_i)*2;
}

int main(){
    scanf("%d %d", &N, &M);
    ans = M;
    int a,b;
    for(i=0; i<N; i++){
        scanf("%d %d", &arr[idx].second, &arr[idx].first);
        if( arr[idx].second>arr[idx].first ) idx++;
    }
    sort(arr, arr+idx);

    if( idx>0 ) drive();
    printf("%lld\n", ans);
    return 0;
}
