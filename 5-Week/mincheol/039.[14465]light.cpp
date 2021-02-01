#include <stdio.h>
#include <algorithm>

using namespace std;

int N,lin,brek,in1,ans;
int arr[100001] = {0,};

void solution(){
    int i, chk=0;
    for(i=1; i<=lin; i++){
        chk += arr[i];
    }
    ans = chk;
    for(; i<=N; i++){
        chk += arr[i] - arr[i-lin];
        ans = min(ans, chk);
    }
}

int main(){
    scanf("%d %d %d", &N, &lin, &brek);
    for(int i=1; i<=brek; i++){
        scanf("%d", &in1);
        arr[in1] = 1;
    }
    solution();
    printf("%d\n", ans);
    return 0;
}
