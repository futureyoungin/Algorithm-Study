#include <stdio.h>
#include <algorithm>

// 게시중 - ++
//        - 자리o? - ++
//                 - 삭제

using namespace std;

typedef struct{int n,i,age;}info;
int frames,up,num=1,_in,tmp;
int tmp_n,tmp_a;
int ids[101]={0};
info ups[21];

bool cmp(const info a, const info b){
    return a.i<b.i;
}

int main(){
    ups[0] = {1001,0,0};
    scanf("%d", &frames);
    scanf("%d", &up);
    for(int i=0; i<up; i++){
        scanf("%d",&_in);

        if( ids[_in]==0 ){              // 게시 안돼있음
            if( num==frames+1 ){                    // 가득 차있으면 맨 뒤 1개 비움
                ids[ups[num-1].i] = 0;
                tmp = num-1;
            }
            else tmp = num;
            for(; ups[tmp-1].n==1; tmp--){          // 같은 크기 중 맨 앞으로
                ids[ups[tmp-1].i]++;
                ups[tmp] = ups[tmp-1];
            }
            ups[tmp] = {1,_in,i};
            ids[_in] = tmp;
            if( num!=frames+1 ) num++;
        }else{                          // 게시 돼있음
            tmp_n = ups[ids[_in]].n+1;
            tmp_a = ups[ids[_in]].age;
            for(tmp=ids[_in]; ups[tmp-1].n<=tmp_n; tmp--){      // 순서 업데이트
                if( ups[tmp-1].n==tmp_n && ups[tmp-1].age>tmp_a ) break;
                ids[ups[tmp-1].i]++;
                ups[tmp] = ups[tmp-1];
            }
            ups[tmp] = {tmp_n, _in, tmp_a};
            ids[_in] = tmp;
        }
    }
    sort(ups+1, ups+frames+1, cmp);
    for(int i=1; i<=frames; i++){
        if( ups[i].i==0 ) continue;
        printf("%d ", ups[i].i);
    }
    return 0;
}
