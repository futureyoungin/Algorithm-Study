#include <iostream>
#include <fstream>

using namespace std;

int cases,n1,n2, ans;

void solution(){
    int num = n2-n1;
    int now = 1;
    ans = 0;
    while( num>=now*2 ){
        ans += 2;
        num -= now++*2;
    }
    while( num>0 ){
        if( num>=now ){
            ans += num/now;
            num %= now;
        }
        now--;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream in("test.txt");
    if( in.is_open() ){
        in>>cases;
        for(int i=0; i<cases; i++){
            in>>n1>>n2;
            solution();
        }
    }
    return 0;
}