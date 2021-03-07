#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


bool bridge[33][12]={false, };
bool visit[33][12]={false, };

int min_line = 10000;
int N, M, H;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> N >> M >> H;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        bridge[a][b] = true;
    }
}

bool simul(){
    for(int i=1; i<=N; i++){
        int cur_line = i;
        for(int j=1; j<=H; j++){
            if(bridge[j][cur_line] == true) cur_line++;
            else if(bridge[j][cur_line-1] == true) cur_line--;
        }
        if(cur_line != i) return false;
    }
    return true;
}

void select_line(int idx, int cnt){
    if(cnt>3) return;
    if(simul()){
        min_line = min(min_line, cnt);
        return;
    }
    for(int i=idx; i<=H; i++){
        for(int j=1; j<N; j++){
            if(bridge[i][j] == true) continue;
            if(bridge[i][j-1] == true) continue;
            if(bridge[i][j+1] == true) continue;
            
            bridge[i][j] = true;
            select_line(i, cnt+1);
            bridge[i][j] = false;
        }
    }
}

void solve(){
    select_line(1,0);
    if(min_line == 10000) min_line = -1;
    cout << min_line;
}

int main()
{
    input();
    solve();
    
    return 0;
}