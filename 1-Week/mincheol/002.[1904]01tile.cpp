#include <iostream>

using namespace std;

int mod = 15746;
int fibo(int n){
    int a=1, b=1;
    if( n==1 ) return 1;
    for(int i=1; i<n; i++){
        if( i%2==1 ) a=(a+b)%mod;
        else b=(a+b)%mod;
    }
    if( n%2==0 ) return a;
    return b;
}

int main(){
    int a;
    cin>>a;
    cout<<fibo(a)<<endl;
    return 0;
}
