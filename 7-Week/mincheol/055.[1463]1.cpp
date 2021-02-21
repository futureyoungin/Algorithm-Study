#include <iostream>
#include <queue>

using namespace std;

int N,ans=0;
bool chk[1000001];
queue<int> qu;

void solution(){
    int num,next,siz=1;
    qu.push(N);
    while( !qu.empty() ){
        num = qu.front();
        qu.pop();
        siz--;
        if( num==1 ) break;
        chk[num] = true;
        if( num%3==0 ){
            next = num/3;
            if( chk[next]==false )
                qu.push(next);
        }
        if( num%2==0 ){
            next = num/2;
            if( chk[next]==false )
                qu.push(next);
        }
        if( chk[num-1]==false )
            qu.push(num-1);
        if( siz==0 ){
            ans++;
            siz = qu.size();
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    solution();
    return 0;
}
