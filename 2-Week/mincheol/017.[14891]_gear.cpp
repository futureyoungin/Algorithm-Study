#include <iostream>
#include <vector>

using namespace std;

vector<int> done(4);
vector<vector<int>> chk(3);
vector<vector<int>> arr(4);
void update(int geari, bool dir){
    if( geari==1 && done[0]==0 ){
        done[0] = 1;
        int tmp = chk[0][0];
        if( dir ){
            if( tmp==0 ) chk[0][0] = 7;
            else chk[0][0]--;
        }else{
            if( tmp==7 ) chk[0][0] = 0;
            else chk[0][0]++;
        }
        if( arr[0][tmp]!=arr[1][chk[0][1]] ) update(2, !dir);
    }else if( geari==4 && done[3]==0 ){
        done[3] = 1;
        int tmp = chk[2][1];
        if( dir ){
            if( tmp==0 ) chk[2][1] = 7;
            else chk[2][1]--;
        }else{
            if( tmp==7 ) chk[2][1] = 0;
            else chk[2][1]++;
        }
        if( arr[3][tmp]!=arr[2][chk[2][0]] ) update(3, !dir);
    }else if( done[geari-1]==0 ){
        done[geari-1] = 1;
        for(int i=1; i>-1; i--){
            int tmp = chk[geari-i-1][i];
            if( dir ){
                if( tmp==0 ) chk[geari-i-1][i] = 7;
                else chk[geari-i-1][i]--;
            }else{
                if( tmp==7 ) chk[geari-i-1][i] = 0;
                else chk[geari-i-1][i]++;
            }
            if( arr[geari-1][tmp]!=arr[geari-2*i][chk[geari-i-1][1-i]] )
                update(geari+1-2*i, !dir);
        }
    }
}

int main(){
    for(int i=0; i<4; i++){
        string a;
        cin>>a;
        for(int j=0; j<8; j++){
            arr[i].push_back(a[j]-'0');
        }
    }
    chk[0] = {2, 6};
    chk[1] = {2, 6};
    chk[2] = {2, 6};

    int K;
    cin>>K;
    for(int i=0; i<K; i++){
        done = {0,0,0,0};
        int a,b;
        bool c;
        cin>>a>>b;
        if( b==1 ) c = true;
        else c = false;
        update(a, c);
    }
    int ans = 0;
    int cnt = 0;
    int forcnt[] = {1,2,4,8};
    int forfor[] = {0,2};
    for(int i : forfor){
        int a = chk[i][0]-2;
        if( a<0 ) a += 8;
        ans += arr[cnt][a]*forcnt[cnt];
        cnt++;
        a = chk[i][1]+2;
        if( a>7 ) a -= 8;
        ans += arr[cnt][a]*forcnt[cnt];
        cnt++;
    }
    cout<<ans;
    return 0;
}
