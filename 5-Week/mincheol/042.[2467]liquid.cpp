#include <stdio.h>
#include <algorithm>

// 투포인터 시작점

using namespace std;

#define INF 0x7fffffff

int N,in1,idx=0,ans=INF;
int arr[100000];

void solution(){
    if( idx==0 ){
        printf("%d %d\n", arr[0], arr[1]);
        return;
    }
    if( idx==-1 ){
        printf("%d %d\n", arr[N-2], arr[N-1]);
        return;
    }

    int sum1=INF,sum2=INF,sum3=INF,sum,left,right;
    if( idx!=0 ) sum1 = abs(arr[idx-1]+arr[idx]);
    sum2 = abs(arr[idx]+arr[idx+1]);
    if( idx<N-2 )sum3 = abs(arr[idx+1]+arr[idx+2]);
    sum = min(sum1, sum2);
    sum = min(sum, sum3);
    if( sum==sum2 ){
        left = idx;
        right = idx+1;
    }else if( sum==sum1 ){
        left = idx-1;
        right = idx;
    }else{
        left = idx+1;
        right = idx+2;
    }
    int ans1,ans2;
    while(1){
        sum = arr[left] + arr[right];
        if( ans>abs(sum) ){
            ans = abs(sum);
            ans1 = arr[left];
            ans2 = arr[right];
        }
        if( sum==0 ) break;
        if( sum<0 ){
            right++;
            if( right==N ) break;
        }else{
            left--;
            if( left==-1 ) break;
        }
    }
    printf("%d %d\n", ans1, ans2);
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", arr+i);
        if( arr[i]<0 ) idx = -1;
        else if( idx==-1 ) idx = i-1;
    }
    solution();
    return 0;
}
