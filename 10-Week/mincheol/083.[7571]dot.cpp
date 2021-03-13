#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M, r,c,ans=0;
vector<vector<int>> arr;
//int row[100000], col[100000];

void solution(){
    sort(arr[0].begin(), arr[0].end());
    sort(arr[1].begin(), arr[1].end());
    int st, ed, stc, edc;
    for(int i=0; i<2; i++){
        st=0, ed=M-1;
        if( arr[i][st]!=arr[i][ed] ){
            stc=1, edc=1;
            while( st<ed ){
                while( arr[i][st]==arr[i][st+1] ) st++, stc++;
                while( arr[i][ed]==arr[i][ed-1] ) ed--, edc++;

                if( stc<edc ){
                    ans += (arr[i][st+1]-arr[i][st])*stc;
                    st++, stc++;
                }else{
                    ans += (arr[i][ed]-arr[i][ed-1])*edc;
                    ed--, edc++;
                }
            }
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    arr.assign(2, vector<int>(M));
    for(int i=0; i<M; i++){
        cin>>arr[0][i]>>arr[1][i];
    }
    solution();
    return 0;
}
