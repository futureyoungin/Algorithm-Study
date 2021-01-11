#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string gear[4];
    int gearPoint[4]={0};
    int K;

    for(int i=0; i<4; ++i) {
        cin >> gear[i];
    }
    cin >> K;
    for(int i=0; i<K; ++i) {
        int num, dir;
        int left, right;
        int gearDir[4]={0};

        cin >> num >> dir;
        --num; // 1~4 까지의 범위를 0~3으로 수정
        left = right = num;
        gearDir[num] = dir;

        while(left>=1){
            if(gear[left][(gearPoint[left]+6)%8] != gear[left-1][(gearPoint[left-1]+2)%8])
                gearDir[left-1] = -gearDir[left];
            else
                break;
            --left;
        }
        while(right<=2){
            if(gear[right][(gearPoint[right]+2)%8] != gear[right+1][(gearPoint[right+1]+6)%8])
                gearDir[right+1] = -gearDir[right];
            else
                break;
            ++right;
        }
        for(int j=0; j<4; ++j) {
            if(gearDir[j] == 1)
                gearPoint[j] = (gearPoint[j]+7)%8;
            else if(gearDir[j] == -1)
                gearPoint[j] = (gearPoint[j]+1)%8;
        }
    }
    int score=0;
    for(int i=0; i<4; ++i) {
        if(gear[i][gearPoint[i]] == '1')
            score += (static_cast<int>(pow(2, i)));
    }
    cout << score << endl;
}