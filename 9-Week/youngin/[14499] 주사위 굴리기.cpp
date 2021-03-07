#include <iostream>
#include <vector>

/* 주사위 left top right bot front behind
동쪽 -->  bot left top right front behind
서쪽 -->  top right bot left front behind
북쪽 -->  left front right behind bot top
남쪽 -->  left behind right front top bot
*/

using namespace std;

int N, M;
int K;
class DICE{
    public :
        int element[6];
        int loc_x, loc_y;
};
DICE dice;

vector<int> command;
int MAP[20][20]={0,};

int to_y[5] ={0, 0, 0, -1, 1};
int to_x[5] ={0, 1, -1, 0, 0};

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin >> dice.loc_y >> dice.loc_x;
    cin >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    int temp;
    for(int i=0; i<K; i++){
        cin >> temp;
        command.push_back(temp);
    }
    for(int i=0; i<6; i++)
        dice.element[i] = 0;
}

void operate_dice(int dir){
    int before_temp, after_temp;
    if(dir ==1){     // Easst
        before_temp = dice.element[0];
        for(int i=0; i<4; i++){
            after_temp = dice.element[(i+1)%4];
            dice.element[(i+1)%4] = before_temp;
            before_temp = after_temp;
        }
    }
    else if(dir==2){ // West
        before_temp = dice.element[0];
        for(int i=3; i>=0; i--){
            after_temp = dice.element[i];
            dice.element[i] = before_temp;
            before_temp = after_temp;
        }
        
    }
    /* 주사위 left top right bot front behind
    
    북쪽 -->  left behind right front bot top*/
    else if(dir==3){ // North
        int top = dice.element[1];
        int bot = dice.element[3];
        int front = dice.element[4];
        int behind = dice.element[5];
        dice.element[1] = front; dice.element[3] = behind;
        dice.element[4] = bot; dice.element[5] = top;
    }
    
    /*           0  1    2    3    4     5
    /* 주사위 left top right bot front behind
    남쪽 -->  left front right behind top bot*/
    else if(dir==4){ // South
        int top = dice.element[1];
        int bot = dice.element[3];
        int front = dice.element[4];
        int behind = dice.element[5];
        dice.element[1] = behind; dice.element[3] = front;
        dice.element[4] = top; dice.element[5] = bot;
    }
    
    if(MAP[dice.loc_y][dice.loc_x] == 0){
        MAP[dice.loc_y][dice.loc_x] = dice.element[3]; // bot
    }
    else{
        dice.element[3] = MAP[dice.loc_y][dice.loc_x];
        MAP[dice.loc_y][dice.loc_x] = 0;
    }
    
}

void solve(){
    int dir;
    for(int i=0; i<command.size(); i++){
        dir = command[i];
        dice.loc_y += to_y[dir], dice.loc_x += to_x[dir];
        if(dice.loc_y < 0 || dice.loc_y >= N || dice.loc_x < 0 || dice.loc_x >= M){
            dice.loc_y -= to_y[dir]; dice.loc_x -= to_x[dir];
            continue;
        }
        operate_dice(dir);
        cout << dice.element[1] << "\n";
        /*for(int i=0; i<6; i++)
            cout << dice.element[i];
        cout << "\n";*/
    }
}

int main(){
    input();
    solve();
    return 0;
}