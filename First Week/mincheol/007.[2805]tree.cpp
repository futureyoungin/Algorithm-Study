#include <iostream>
#include <map>

// if문에서 일시적인 overflow -> long long 사용
// int형 계산은 (long long)캐스팅 후 계산

using namespace std;

int N,M,tmp,res,get_len=0;
long long chk;
map<int,int,greater<int> > save;

void cut_tree(){
    auto iter = save.begin();
    while( M>0 ){
        res = iter->first;
        get_len += iter->second;
        iter++;

        if( iter==save.end() ) tmp = 0;
        else tmp = iter->first;

        chk = (long long)(res-tmp)*get_len;
        if( chk<M ){
            M -= chk;
        }else{
            res -= (M/get_len);
            if( M%get_len ) res--;
            break;
        }
    }
}

int main(){
    cin>>N>>M;
    int a;
    for(int i=0; i<N; i++){
        cin>>a;
        auto iter = save.find(a);
        if( iter!=save.end() ){
            iter->second++;
        }else{
            save[a] = 1;
        }
        //qu.push(a);
    }

    cut_tree();
    cout<<res<<endl;
    return 0;
}
