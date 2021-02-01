#include <stdio.h>

using namespace std;

int N,L,ans=0;
int arr[100][100];

void solution(){
    int r,c,i,pre,now,chk,up_or_down;
    bool isok;
    for(i=0; i<2; i++){
        for(r=0; r<N; r++){
            if( i==0 ) pre = arr[r][0];
            else pre = arr[0][r];
            chk = 1;
            up_or_down = 0;
            isok = true;
            for(c=1; c<N; c++){
                if( i==0 ) now = arr[r][c];
                else now = arr[c][r];
                if( pre-1==now ){         // 내려감
                    if( up_or_down==-1 ){       // 이전에도 내려옴
                        if( chk<L ){
                            isok = false;
                            break;
                        }
                    }else up_or_down = -1;
                    chk = 0;
                }else if( pre+1==now ){   // 올라감
                    if( up_or_down==-1 ){       // 이전에는 내려옴
                        if( chk<2*L ){
                            isok = false;
                            break;
                        }
                    }else if( chk<L ){
                        isok = false;
                        break;
                    }
                    up_or_down = 1;
                    chk = 0;
                }else if( pre!=now ){     // 2층 이상
                    isok = false;
                    break;
                }
                chk++;
                pre = now;
            }
            if( !isok ) continue;
            if( up_or_down==-1 && chk<L ) continue;
            ans++;
        }
    }
}

int main(){
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    solution();
    printf("%d\n", ans);
    return 0;
}
