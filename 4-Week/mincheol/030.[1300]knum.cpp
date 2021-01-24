#include <stdio.h>
#include <algorithm>

using namespace std;

long long N;
int k,i;

void bin(){
    int left,mid,right,res;
    left=1, right=(int)min(N*N, (long long)1000000000);

    while( left<right ){
        mid = (left+right)/2;
        res = 0;

        for(i=1; i<=N; i++)
            res += min(mid/i, (int)N);

        if( res>=k ) right = mid;
        else left = mid+1;
    }
    printf("%d\n", left);
}

int main(){
    scanf("%d", &N);
    scanf("%d", &k);
    bin();
    return 0;
}
