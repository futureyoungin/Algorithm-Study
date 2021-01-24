#include <stdio.h>

// 81856 81933

using namespace std;

int L,R,ans=0;

void solution(){
    int mod = 10;
    int div = 1;
    int tmp;
    for(int i=0; i<9; i++){
        tmp = L%mod;
        if( tmp/div==8 ){
            if( L+(div*9-tmp)<=R ) L += (div*9-tmp);
            else ans++;
        }
        mod *= 10;
        div *= 10;
    }
    printf("%d\n", ans);
}

int main(){
    scanf("%d %d", &L, &R);
    solution();
    return 0;
}
