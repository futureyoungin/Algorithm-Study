#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

int nodes,edges,in1,in2;
vector<int> llist[20001];
bool chk[20001];
int arr[20001];
queue<int> qu;

void bfs(){
    int now,siz,idx=0,limit,cnt=0;
    qu.push(1);
    chk[1] = true;
    siz = 1;
    limit = nodes-siz;
    while( !qu.empty() ){
        now = qu.front();
        qu.pop();
        arr[idx++] = now;
        siz--;
        nodes--;
        //cout<<now<<" ";
        for(int i : llist[now]){
            if( chk[i]==false ){
                qu.push(i);
                chk[i] = true;
            }
        }
        if( siz==0 ){
            //cout<<"\n";
            if( qu.empty() ) break;
            siz = qu.size();
            idx = 0;
            cnt++;
        }
    }
    sort(arr, arr+idx);
    cout<<arr[0]<<" "<<cnt<<" "<<idx<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*cin>>nodes>>edges;
    for(int i=0; i<edges; i++){
        cin>>in1>>in2;
        llist[in1].push_back(in2);
        llist[in2].push_back(in1);
    }*/
    ifstream in("test.txt");
    if( in.is_open() ){
        in>>nodes>>edges;
        for(int i=0; i<edges; i++){
            in>>in1>>in2;
            llist[in1].push_back(in2);
            llist[in2].push_back(in1);
        }
    }
    bfs();
    return 0;
}
