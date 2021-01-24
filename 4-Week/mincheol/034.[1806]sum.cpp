#include <stdio.h>

using namespace std;

int len,goal,in1,ans=0;
int arr[100000] = {0,};

void solution(){
    int st=0,ed=1;
    int acc;

    while(1){
        acc = arr[ed]-arr[st];
        if( acc<goal ){
            if( ed==len ) return;
            if( ans!=0 ) st++;
            ed++;
        }else{
            ans = ed-st;
            if( ans==1 ) return;
            st++;
        }
    }
}

int main(){
    scanf("%d %d", &len, &goal);
    for(int i=1; i<=len; i++){
        scanf("%d", &in1);
        arr[i] = arr[i-1]+in1;
    }
    solution();
    printf("%d\n", ans);
    return 0;
}
