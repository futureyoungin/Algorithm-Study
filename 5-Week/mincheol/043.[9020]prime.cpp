#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int cases,n,cmp;
vector<int> prime(1,2);

bool find_greater(int n){
    return n>=cmp;
}

void solution(){
    vector<int>::iterator left,right;

    cmp = n/2;
    right = find_if(prime.begin(), prime.end(), find_greater);
    if( *right==cmp ) left = right;
    else left = right-1;

    int tmp = (*left)+(*right);
    while( tmp!=n ){
        if( tmp>n ) left--;
        else right++;
        tmp = (*left)+(*right);
    }
    printf("%d %d\n", *left, *right);
}

int main(){
    for(int i=3; i<10001; i++){
        for(int j : prime){
            if( i%j==0 ) break;
            if( j==prime.back() ) prime.push_back(i);
        }
    }
    scanf("%d", &cases);
    for(int i=0; i<cases; i++){
        scanf("%d", &n);
        solution();
    }
    return 0;
}
