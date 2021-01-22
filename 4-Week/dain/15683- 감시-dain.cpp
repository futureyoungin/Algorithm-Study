#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;

int N, M, answer;
int board[9][9];
int cpy_board[9][9];
int cctv_dir[9];

int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};

vector<pair<int, int>> cctv;

void copyboard(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cpy_board[i][j] = board[i][j];
        }
    }
}

void get_straight(int x,int y,int d){
    int next_x = x, next_y = y;
    while(true){
        next_x += dx[d]; next_y += dy[d];
        if(next_x<0 || next_y<0 || next_x >= N || next_y >= M) break;
        if(cpy_board[next_x][next_y] == 6) break;
        if(cpy_board[next_x][next_y] == 0) cpy_board[next_x][next_y] = 7;
    }
}

void set_cctv(){
    for(int i=0; i<cctv.size(); i++){
        int x = cctv[i].first, y = cctv[i].second;

        if(cpy_board[x][y]==1){
            get_straight(x, y, cctv_dir[i]);
        }else if(cpy_board[x][y]==2){
            if(cctv_dir[i] == 1){
                get_straight(x,y,1);
                get_straight(x,y,2);
            }else{
                get_straight(x,y,3);
                get_straight(x,y,4);
            }
        }else if(cpy_board[x][y]==3){
            if(cctv_dir[i] == 1){
                get_straight(x,y,1);
                get_straight(x,y,4);
            }else if(cctv_dir[i] == 2){
                get_straight(x,y,1);
                get_straight(x,y,3);
            }else if(cctv_dir[i] == 3){
                get_straight(x,y,2);
                get_straight(x,y,3);
            }else if(cctv_dir[i] == 4){
                get_straight(x,y,2);
                get_straight(x,y,4);
            }
        }else if(cpy_board[x][y]==4){
            if(cctv_dir[i] == 1){
                get_straight(x,y,1);
                get_straight(x,y,2);
                get_straight(x,y,4);
            }else if(cctv_dir[i] == 2){
                get_straight(x,y,1);
                get_straight(x,y,3);
                get_straight(x,y,4);
            }else if(cctv_dir[i] == 3){
                get_straight(x,y,1);
                get_straight(x,y,2);
                get_straight(x,y,3);
            }else if(cctv_dir[i] == 4){
                get_straight(x,y,2);
                get_straight(x,y,3);
                get_straight(x,y,4);
            }
        }else if(cpy_board[x][y]==5){
            get_straight(x,y,1);
            get_straight(x,y,2);
            get_straight(x,y,3);
            get_straight(x,y,4);
        }   
    }
}

int get_bs(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(cpy_board[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void dfs(int idx,int cnt){
    if(cnt == cctv.size()){
        copyboard();
        set_cctv();
        answer = min(answer,get_bs());
        return;
    }
    
    int x = cctv[idx].first, y = cctv[idx].second;
    
    for(int k=1; k<=4; k++){
        if(board[x][y] == 5 && k > 1) continue;
        if(board[x][y] == 2 && k > 2) continue;
        
        cctv_dir[idx] = k;
        dfs(idx+1,cnt+1);
        cctv_dir[idx] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5)
                cctv.push_back(pair<int, int>(i,j));
        }
    }
    
    answer = INF;
    dfs(0,0);
    cout << answer << "\n";
    
    return 0;
}