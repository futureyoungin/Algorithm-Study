#include <iostream>
#include <fstream>

using namespace std;

int N,L,R;
int arr[50][50];
int arr2[50][50];
int unionsp[2501] = {0,};
int unionsc[2501] = {0,};
int dr[]={0,1,0,-1}, dc[]={1,0,-1,0};
bool isgo;

void find_union(int row, int col, int num){
    int r,c,diff;
    arr2[row][col] = num;
    unionsp[num] += arr[row][col];
    unionsc[num]++;
    for(int i=0; i<4; i++){
        r = row+dr[i], c = col+dc[i];
        if( r==-1 || r==N || c==-1 || c==N ) continue;
        if( arr2[r][c]!=0 ) continue;
        diff = abs(arr[row][col]-arr[r][c]);
        if( diff<L || diff>R ) continue;
        find_union(r, c, num);
    }
}

void solution(){
    int cnt,ans=0;
    while( 1 ){
        cnt = 1;
        isgo = false;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if( arr2[i][j]==0 ){
                    find_union(i, j, cnt);
                    if( unionsc[cnt]>1 ) isgo = true;
                    cnt++;
                }
            }
        }
        if( isgo ){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if( unionsc[arr2[i][j]]>1 ){
                        arr[i][j] = unionsp[arr2[i][j]]/unionsc[arr2[i][j]];
                    }
                    arr2[i][j] = 0;
                }
            }
            for(int i=1; i<=2500; i++){
                if( unionsc[i]>0 ) unionsc[i]=0, unionsp[i]=0;
                else break;
            }
            ans++;
        }else break;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout<<"q"<<"\n";
    ifstream in("test.txt");
    if( in.is_open() ){
        in>>N>>L>>R;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                in>>arr[i][j];
            }
        }
    }
    //cout<<"s";
    solution();
    return 0;
}
