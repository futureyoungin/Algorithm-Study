#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct{int r,c,type;}st;
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};
int turn[] = {4,2,4,4,1};
vector<st> cctv;
vector<int> deflt[5];

int se,ga,chk=0,ans;

st fmove(st now, int dir){
    now.r += dr[dir];
    now.c += dc[dir];
    if( now.r<0 || now.r==se || now.c<0 || now.c==ga )
        now.r = -1;
    return now;
}

void dfs(int idx, vector<vector<int>> chk_arr, int chk){
    st now = cctv[idx];
    vector<int> dirs = deflt[now.type];

    st next;
    vector<vector<int>> next_arr;
    int next_chk;
    for(int i=0; i<turn[now.type]; i++){
        next_arr = chk_arr;
        next_chk = chk;
        for(int j : dirs){
            next = now;
            while(1){
                next = fmove(next, j);
                if( next.r==-1 ) break;
                if( next_arr[next.r][next.c]==6 ) break;
                if( next_arr[next.r][next.c]==0 ){
                    next_chk--;
                    next_arr[next.r][next.c] = -1;
                }
            }
        }

        if( idx+1==cctv.size() ) ans = min(ans, next_chk);
        else dfs(idx+1, next_arr, next_chk);

        for(int j=0; j<dirs.size(); j++){
            dirs[j] = (dirs[j]+1)%4;
        }
    }
}

int main(){
    deflt[0] = {1};
    deflt[1] = {1,3};
    deflt[2] = {0,1};
    deflt[3] = {0,1,3};
    deflt[4] = {0,1,2,3};
    vector<vector<int>> arr(8,vector<int>(8,0));

    scanf("%d %d", &se, &ga);
    for(int i=0; i<se; i++){
        for(int j=0; j<ga; j++){
            scanf("%d", &arr[i][j]);
            if( arr[i][j]==0 ) chk++;
            else if( arr[i][j]!=6 ){
                cctv.push_back({i, j, arr[i][j]-1});
            }
        }
    }
    /*ifstream in("test.txt");
    if( in.is_open() ){
        in>>se>>ga;
        for(int i=0; i<se; i++){
            for(int j=0; j<ga; j++){
                in>>arr[i][j];
                if( arr[i][j]==0 ) chk++;
                else if( arr[i][j]!=6 ){
                    cctv.push_back({i, j, arr[i][j]-1});
                }
            }
        }
    }*/
    ans = chk;
    if( cctv.size()>0 ) dfs(0, arr, chk);
    printf("%d\n", ans);
    return 0;
}
