#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>

// - + 연산자 실수
// bfs 호출 마다 queue 초기화해야함

using namespace std;

typedef struct{int r,c;}coo;
int N,M,vi_siz=0,null_siz=0,ans=3000;
int dr[] = {0,1,0,-1}, dc[] = {1,0,-1,0};
int arr[50][50];
int arr2[50][50];
coo vi[10];
coo selec[10];

coo fmove(coo now, int dir){
    now.r += dr[dir];
    now.c += dc[dir];
    if( now.r==N || now.r<0 || now.c==N || now.c<0 )
        now.r = -1;
    return now;
}

void bfs(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            arr2[i][j] = arr[i][j];

    queue<coo> qu;
    for(int i=0; i<M; i++){
        qu.push(selec[i]);
        arr2[selec[i].r][selec[i].c] = 3;
    }
    int siz = M, dep = 1, limit = null_siz;
    coo now,next;
    while( !qu.empty() ){
        now = qu.front();
        qu.pop();
        siz--;
        for(int i=0; i<4; i++){
            next = fmove(now, i);
            if( next.r==-1 ) continue;
            if( arr2[next.r][next.c]==1 || arr2[next.r][next.c]==3 ) continue;
            if( arr2[next.r][next.c]==0 ) limit--;
            qu.push(next);
            arr2[next.r][next.c] = 3;
        }
        if( siz==0 ){
            if( limit==0 ){
                ans = min(ans, dep);
                return;
            }
            siz = qu.size();
            dep++;
        }
    }
}

void select_places(int st, int cnt){
    for(int i=st; i<vi_siz-cnt+1; i++){
        selec[M-cnt] = vi[i];
        if( cnt==1 ) bfs();
        else select_places(i+1, cnt-1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            if( arr[i][j]==0 ) null_siz++;
            if( arr[i][j]==2 ) vi[vi_siz++] = {i,j};
        }
    }*/
    ifstream in("test.txt");
    if( in.is_open() ){
        in>>N>>M;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                in>>arr[i][j];
                if( arr[i][j]==0 ) null_siz++;
                if( arr[i][j]==2 ) vi[vi_siz++] = {i,j};
            }
        }
    }

    if( null_siz==0 ) cout<<0<<"\n";
    else {
        select_places(0, M);
        if( ans==3000 ) cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
