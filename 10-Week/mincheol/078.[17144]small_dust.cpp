#include <iostream>
#include <fstream>

using namespace std;

typedef struct{int r,c;}coo;
int R,C,T, total=0,p1=-1,p2=-1;
int arr[50][50];
int arr2[50][50];
int dr[]={0,1,0,-1}, dc[]={1,0,-1,0};

coo fmove(coo now, int dir){
    now.r += dr[dir];
    now.c += dc[dir];
    if( now.r==-1 || now.r==R || now.c==-1 || now.c==C )
        now.r = -1;
    return now;
}

void spread(){
    coo next;
    int now;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            now = arr[i][j]/5;
            if( now==0 ) continue;
            for(int k=0; k<4; k++){
                next = fmove({i,j}, k);
                if( next.r==-1 ) continue;
                if( arr[next.r][next.c]==-1 ) continue;
                arr2[next.r][next.c] += now;
                arr[i][j] -= now;
            }
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            arr[i][j] += arr2[i][j];
            arr2[i][j] = 0;
        }
    }
}

void clear(){
    int r=p1-1, c=0;
    total -= arr[r][c];
    while( r>0 ) arr[r][c] = arr[r-1][c], r--;
    while( c<C-1 ) arr[r][c] = arr[r][c+1], c++;
    while( r<p1 ) arr[r][c] = arr[r+1][c], r++;
    while( c>1 ) arr[r][c] = arr[r][c-1], c--;
    arr[r][c] = 0;
    r=p2+1, c=0;
    total -= arr[r][c];
    while( r<R-1 ) arr[r][c] = arr[r+1][c], r++;
    while( c<C-1 ) arr[r][c] = arr[r][c+1], c++;
    while( r>p2 ) arr[r][c] = arr[r-1][c], r--;
    while( c>1 ) arr[r][c] = arr[r][c-1], c--;
    arr[r][c] = 0;
}

void solution(){
    for(int i=0; i<T; i++){
        spread();
        clear();
    }
    cout<<total<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream in("test.txt");
    if( in.is_open() ){
        in>>R>>C>>T;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                in>>arr[i][j];
                if( arr[i][j]>0 ) total += arr[i][j];
                else if( arr[i][j]==-1 ){
                    if( p1==-1 ) p1 = i;
                    else p2 = i;
                }
            }
        }
    }
    solution();
    return 0;
}