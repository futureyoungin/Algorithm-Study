#include <iostream>
#include <cstring>


using namespace std;

int N, M, T; // 원판 개수, 원판에 적힌 수, 테스트
int circle[51][51]={0,};
bool erase_target[51][51]={false, };

void input(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   cin >> N >> M >> T;
   for(int i=1; i<=N; i++){
       for(int j=0; j<M; j++){
           cin >> circle[i][j];
       }
   }
}

double find_mid(){
    int sum=0, cnt=0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            if((circle[i][j] != 0) && (circle[i][j] != -1)){
                sum += circle[i][j];
                cnt++;
            }
        }
    }
    if(cnt==0) return 0;
    double ret = sum/(double)cnt;
    return ret;
}

int find_sum(){
   int sum=0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            if((circle[i][j] != 0) && (circle[i][j] != -1)){
                sum += circle[i][j];
            }
        }
    }
    return sum;
}

void rotating(){
    int n, dir, dis; // number / direction / distance
    int before_temp, next_temp;
    cin >> n >> dir >> dis;
    
    for(int k=1; k*n<=N; k++){ // 배수의 원판
        for(int rotate=0; rotate<dis; rotate++){ // 회전의 횟수
            if(dir==0){// clockwise
                before_temp=circle[k*n][0];
                for(int i=0; i<M; i++){
                    next_temp = circle[k*n][(i+1)%M];  
                    circle[k*n][(i+1)%M] = before_temp;
                    before_temp = next_temp;
                }
            }
            else{
                before_temp = circle[k*n][0];
                for(int i=0; i<M; i++){
                    next_temp = circle[k*n][M-1-i];
                    circle[k*n][M-1-i] = before_temp;
                    before_temp = next_temp;
                }
            }
        }
    }
}

bool erasing(){
    bool ret = false;
    memset(erase_target, false, sizeof(erase_target));
    int before_target, cur_target;
    int before_row, before_col;
    for(int i=0; i<M; i++){ // 다른 원판끼리 인접하는 경우
        before_target = 0;
        before_row = 0, before_col = 0;
        for(int j=1; j<=N; j++){
            cur_target = circle[j][i];
            if(before_target == cur_target && cur_target != -1){
                erase_target[before_row][before_col] = true;
                erase_target[j][i] = true;
            }
            before_target = circle[j][i];
            before_row = j, before_col = i;
        }
    }
    for(int i=1; i<=N; i++){ // 같은 원판 안에서 인접하는 경우
        for(int j=0; j<M; j++){
            if(circle[i][j] == circle[i][(j+1)%M] && circle[i][j] != -1)
                erase_target[i][j] = erase_target[i][(j+1)%M] = true;
        }
    }
    
    for(int i=1; i<=N; i++){ // Erase Circle
        for(int j=0; j<M; j++){
            if(erase_target[i][j]){
                circle[i][j] = -1;
                ret = true;      
            }
        }
    }
    return ret;
}

void up_and_down(){
    double mid = find_mid();
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            if((double)circle[i][j] > mid && circle[i][j] != -1)
                circle[i][j]--;
            else if((double)circle[i][j] < mid && circle[i][j] != -1)
                circle[i][j]++;
                
        }
    }
}

void print_circle(){
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            cout << circle[i][j] << "  ";
        }
        cout << "\n";
    }
}

int solve(){
    for(int i=0; i<T; i++){
        rotating();
        if(!erasing()){
            up_and_down();
        }
    }
    return (int)find_sum();
}

int main()
{
   input();
   cout << solve();
   return 0;
}