#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
/*
int n,i,in,vidx=0,isno=0,mini;
vector<vector<int>> segm;
vector<int> sorted;

void solution();

int main(){
    scanf("%d", &n);
    scanf("%d", &in);
    segm.push_back({in,1});
    sorted.push_back(in);
    mini = in;
    for(i=1; i<n; i++){
        scanf("%d", &in);

        if( in<segm[vidx][0] ){         // 머리보다 작음
            if( in>mini ) isno = 1;    // 최소보다 큼 - 불가능
            else{
                segm[vidx][1]++;
                mini = in;
                sorted.push_back(in);
            }
        }else{          // 머리보다 큼
            segm.push_back({in,1});
            sorted.push_back(in);
            mini = in;
            vidx++;
        }
    }

    solution();
    return 0;
}

void solution(){
    if( isno ){
        printf("NO\n");
        return;
    }
    sort(sorted.begin(), sorted.end());
    i = 0;
    int j;
    for(auto iter : segm){
        for(; i<sorted.size(); i++){
            printf("+\n");
            if( sorted[i]==iter[0] ){
                i++;
                break;
            }
        }
        for(j=0; j<iter[1]; j++)
            printf("-\n");
    }
}
*/
int n,i,j,head=0,tail,in,idx=0;
char ans[200000];

int main(){
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &in);

        if( in>head ){
            for(j=head; j<in; j++){
                ans[idx++] = '+';
                ans[idx++] = '\n';
            }
            ans[idx++] = '-';
            ans[idx++] = '\n';
            head = in;
            tail = in;
        }else{
            if( in>tail ){
                printf("NO\n");
                return 0;
            }
            ans[idx++] = '-';
            ans[idx++] = '\n';
            tail = in;
        }
    }
    ans[idx] = '\0';

    printf("%s\n", ans);
    return 0;
}
