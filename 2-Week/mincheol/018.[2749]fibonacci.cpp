#include <stdio.h>
#include <vector>

// 피사노 주기
// 행렬 곱

using namespace std;

int mod = 1000000;
long long n;
vector<int> arr = {0,1};

int get_period(){
    int a[2]={0,1},b=0,idx=0,len=2;
    while( idx!=len-1 ){
        a[b] = (a[0]+a[1])%mod;
        arr.push_back(a[b]);
        if( *(arr.end()-1)==arr[idx] ){
            idx++;
        }else{
            len += idx+1;
            idx = 0;
        }
        b = (b+1)%2;
    }
    return len;
}

int main(){
    scanf("%lld", &n);

    int peri = get_period();
    printf("%d\n", arr[n%peri]);

    return 0;
}
