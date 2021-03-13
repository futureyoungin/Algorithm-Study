#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int cases,n;
string arr[10000];

void solution(){
    sort(arr, arr+n);
    int j;
    for(int i=1; i<n; i++){
        for(j=0; j<arr[i-1].length(); j++){
            if( arr[i-1][j]!=arr[i][j] ) break;
        }
        if( j==arr[i-1].length() ){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream in("test.txt");
    if( in.is_open() ){
        in>>cases;
        for(int i=0; i<cases; i++){
            in>>n;
            for(int j=0; j<n; j++){
                in>>arr[j];
            }
            solution();
        }
    }
    return 0;
}
