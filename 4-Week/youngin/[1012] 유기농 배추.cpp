#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int cabbage[50][50] = {0, };
int visit[50][50] ={0, };
int to_x[4] = {1, -1, 0, 0};
int to_y[4] = {0, 0, -1, 1};
int T,n_cab, lim_x, lim_y;
queue<pair<int,int>> cabbages;

void input(){
    cin >> lim_x >> lim_y >> n_cab;
    int x, y;
    for(int i=0; i<n_cab; i++){
        cin >> x >> y;
        cabbages.push(make_pair(x,y));
        cabbage[x][y] = 1;
    }
}

void travel(int start_x, int start_y){
    if(start_x<0 || start_x >= lim_x || start_y <0 || start_y >= lim_y)
        return;
    if(cabbage[start_x][start_y] == 0)
        return;
    if(visit[start_x][start_y] == 1)
        return;
    
    visit[start_x][start_y] =1;
    int temp_x, temp_y;
    for(int i=0; i<4; i++){
        temp_x = start_x + to_x[i], temp_y = start_y + to_y[i];
        travel(temp_x, temp_y);
    }
}

int min_larva(){
    int n_larva = 0;
    int x, y;
    while(!cabbages.empty()){
        x = cabbages.front().first, y=cabbages.front().second;
        cabbages.pop();
        if(visit[x][y])
            continue;
        else
            n_larva++;
        travel(x, y);
    }
    return n_larva;
}

void all_clear(){
    memset(visit, 0, sizeof(visit));
    memset(cabbage, 0, sizeof(cabbage));
}

int main(){
    cin >> T;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i=0; i<T; i++){
        input();
        cout << min_larva() << "\n";
        all_clear();
    }
    return 0;
}