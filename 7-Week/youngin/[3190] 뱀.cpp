#include <iostream>
#include <queue>
#include <utility>


using namespace std;

#define APPLE 10
#define SNAKE -1

enum{UP=0, DOWN, LEFT, RIGHT};

int N, K;
int seconds=0;
int board[110][110]={0,};
int to_y[4] = {-1, 1, 0, 0}; // Up, DOWN, LEFT, RIGHT
int to_x[4] = {0, 0, -1, 1};
int cur_dir = RIGHT;
bool G_END=false;

queue<pair<int,int>> tail; // y,x
pair<int,int> head;

bool game_end(){
    if(head.first < 1 || head.first > N || head.second < 1 || head.second > N)
        return true;
    if(board[head.first][head.second] == SNAKE)
        return true;
    return false;
}


void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int temp_y, temp_x;
    cin >> N >> K;
    for(int i=0; i<K; i++){
        cin >> temp_y >> temp_x;
        board[temp_y][temp_x] = APPLE;
    }
    tail.push(make_pair(1,1));
    board[1][1] = SNAKE;
}

void gaming(int ch_second, char ch_dir){
    while(seconds != ch_second){
        seconds++;
        head.first += to_y[cur_dir];
        head.second += to_x[cur_dir];
        if(game_end()){
            G_END = true;
            return;
        }   
        if(board[head.first][head.second]==0){ // if not apple
            int tail_y = tail.front().first;
            int tail_x = tail.front().second;
            board[tail_y][tail_x] = 0;
            tail.pop();
        }
        board[head.first][head.second] = SNAKE;
        tail.push(make_pair(head.first, head.second));
    }
     
    if(ch_dir == 'D'){
        if(cur_dir==UP)
            cur_dir = RIGHT;
        else if(cur_dir==DOWN)
            cur_dir = LEFT;
        else if(cur_dir==RIGHT)
            cur_dir=DOWN;
        else{
            cur_dir=UP;
        }
    }
    else{
        if(cur_dir==UP)
            cur_dir = LEFT;
        else if(cur_dir==DOWN)
            cur_dir = RIGHT;
        else if(cur_dir==RIGHT)
            cur_dir=UP;
        else{
            cur_dir=DOWN;
        }
    }  
}

void GAME(){
    int change;
    int ch_second;
    char ch_dir;
    head.first=1, head.second=1;
    cin >> change;
    for(int i=0; i<change; i++){
        if(G_END){
            cout << seconds;
            return;
        }
        cin >> ch_second >> ch_dir;
        gaming(ch_second, ch_dir);
        
    }
    if(G_END){
        cout << seconds;
        return;
    }
    
    if(!G_END){
        while(!G_END){
            seconds++;
            head.first += to_y[cur_dir];
            head.second += to_x[cur_dir];
            if(game_end()){
                G_END = true;
                cout << seconds;
                return;
            }
            if(board[head.first][head.second]==0){ // if not apple
                int tail_y = tail.front().first;
                int tail_x = tail.front().second;
                board[tail_y][tail_x] = 0;
                tail.pop();
            }
            board[head.first][head.second] = SNAKE;
            tail.push(make_pair(head.first, head.second));
            
        }
    }
    
}

int main(){
    input();
    GAME();
    return 0;
}