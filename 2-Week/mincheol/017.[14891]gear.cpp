#include <stdio.h>

using namespace std;

char buf[10];
bool inb;
int gears[4][8],n,in1,in2;
int chk[4][2] = {{6,2},{6,2},{6,2},{6,2}};

// true-시계, false-반시계
void update(int gear_num, bool spin, int dir){
    int left = gears[gear_num][chk[gear_num][0]];
    int right = gears[gear_num][chk[gear_num][1]];

    if( dir==1 || dir==2 )  // 왼쪽
        if( gear_num!=0 && (left^gears[gear_num-1][chk[gear_num-1][1]]) )
            update(gear_num-1, !spin, 1);
    if( dir==0 || dir==2 )  // 오른쪽
        if( gear_num!=3 && (right^gears[gear_num+1][chk[gear_num+1][0]]) )
            update(gear_num+1, !spin, 0);

    if( spin ){
        chk[gear_num][0] = (8+chk[gear_num][0]-1)%8;
        chk[gear_num][1] = (8+chk[gear_num][1]-1)%8;
    }else{
        chk[gear_num][0] = (chk[gear_num][0]+1)%8;
        chk[gear_num][1] = (chk[gear_num][1]+1)%8;
    }
}


int main(){
    for(int i=0; i<4; i++){
        scanf("%s", buf);
        for(int j=0; j<8; j++){
            gears[i][j] = buf[j]-'0';
        }
    }
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d",&in1, &in2);
        if( in2==1 ) inb=true;
        else inb=false;
        update(in1-1, inb, 2);
    }

    int ans = 1*gears[0][(chk[0][0]+2)%8] + 2*gears[1][(chk[1][0]+2)%8] +
              4*gears[2][(chk[2][0]+2)%8] + 8*gears[3][(chk[3][0]+2)%8];
    printf("%d\n", ans);
    return 0;
}
