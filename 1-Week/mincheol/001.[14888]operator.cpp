#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
int maxi=-1000000000, mini=1000000000, N;

void dfs(vector<int> oper, int acc, int i){
    if( i==N ){
        if( maxi<acc ) maxi = acc;
        if( mini>acc ) mini = acc;
        return;
    }
    int a=nums[i];
    if( oper[0]>0 ){
        vector<int> tmp = oper;
        int nacc = acc+a;
        tmp[0]--;
        dfs(tmp, nacc, i+1);
    }
    if( oper[1]>0 ){
        vector<int> tmp = oper;
        int nacc = acc-a;
        tmp[1]--;
        dfs(tmp, nacc, i+1);
    }
    if( oper[2]>0 ){
        vector<int> tmp = oper;
        int nacc = acc*a;
        tmp[2]--;
        dfs(tmp, nacc, i+1);
    }
    if( oper[3]>0 ){
        vector<int> tmp = oper;
        int nacc = acc/a;
        tmp[3]--;
        dfs(tmp, nacc, i+1);
    }
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> oper = {a,b,c,d};

    dfs(oper, nums[0], 1);
    cout<<maxi<<endl<<mini;
    return 0;
}
