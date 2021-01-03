#include <stdio.h>
#include <algorithm>

// iostreamÀº ´À¸²

using namespace std;

pair<int, int> lines[1000000];
int N,i,res=0;

void get_len(){
    sort(lines, lines+N);
    pair<int, int> segm;
    segm = lines[0];

    for(i=1; i<N; i++){
        if( lines[i].first<=segm.second ){
            if( lines[i].second>segm.second ){
                segm.second = lines[i].second;
            }
        }else{
            res += segm.second-segm.first;
            segm = lines[i];
        }
    }
    res += segm.second-segm.first;
}

int main(){
    scanf("%d",&N);
    for(i=0; i<N; i++){
        scanf("%d %d", &lines[i].first, &lines[i].second);
    }

    get_len();
    printf("%d\n", res);
    return 0;
}
