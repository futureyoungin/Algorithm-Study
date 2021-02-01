#include <stdio.h>
#include <map>

using namespace std;

int nodes;
char in1,in2,in3;
map<char, pair<int,int>> map1;

void order(char node, int mode){
    char left=map1[node].first;
    char right=map1[node].second;
    if( mode==1 ) printf("%c", node);
    if( left!='.' ) order(left, mode);
    if( mode==2 ) printf("%c", node);
    if( right!='.' ) order(right, mode);
    if( mode==3 ) printf("%c", node);
}

int main(){
    scanf("%d", &nodes);
    for(int i=0; i<nodes; i++){
        scanf(" %c %c %c", &in1, &in2, &in3);
        map1[in1] = make_pair(in2, in3);
    }
    order('A', 1);
    printf("\n");
    order('A', 2);
    printf("\n");
    order('A', 3);
    return 0;
}
