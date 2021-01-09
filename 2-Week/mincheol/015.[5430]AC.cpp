#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

int T,arr_size,sti,endi,state,tmp;
int dx[2] = {1,-1};
char str[100002], _in;
int arr[100000], in_idx, buf;

void solution(){
    sti=0, endi=arr_size;
    state=0;
    for(int i=0; i<strlen(str); i++){
        if( str[i]=='R' ){
            tmp = endi-dx[state];
            endi = sti-dx[state];
            sti = tmp;
            state = (state+1)%2;
        }else if( str[i]=='D' ){
            if( sti==endi || arr_size==0 ){
                printf("error\n");
                return;
            }
            sti += dx[state];
        }
    }
    printf("[");
    if( state==0 ){
        for(int i=sti; i<endi; i++){
            printf("%d", arr[i]);
            if( i!=endi-1 ) printf(",");
        }
    }else{
        for(int i=sti; i>endi; i--){
            printf("%d", arr[i]);
            if( i!=endi+1 ) printf(",");
        }
    }
    printf("]\n");
}

int main(){
    ifstream in("test.txt");
    if( in.is_open() ){
        in>>T;
        for(int i=0; i<T; i++){
            in_idx = 0;
            buf = 0;
            in>>str;
            in>>arr_size;
            while(1){
                in.get(_in);
                if( _in=='[' || _in=='\n') continue;
                if( _in==',' ){
                    arr[in_idx++] = buf;
                    buf = 0;
                    //printf("%d ", arr[in_idx-1]);
                    continue;
                }
                if( _in==']' ){
                    arr[in_idx++] = buf;
                    //printf("%d ", arr[in_idx-1]);
                    break;
                }
                buf = buf*10 + _in-'0';
            }
            solution();
        }
    }

    return 0;
}
