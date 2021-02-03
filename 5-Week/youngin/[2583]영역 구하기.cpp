#include <iostream>
#include <algorithm>

using namespace std;

int M,N,K;
int area[100][100]={0, };
int area_cnt=0;
int areas[10000]={0};
int to_x[4] = {1, -1, 0, 0};
int to_y[4] = {0, 0, -1, 1};

void fill_rectangle(int x1, int y1, int x2, int y2){
    for(int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            area[i][j] = -1;
        }
    }
}


void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> K;
    int x1, y1, x2, y2;
    for(int i=0; i<K; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        fill_rectangle(y1, x1, y2-1, x2-1);
    }
}

void fill_color(int x, int y){
    int temp_x, temp_y;
    if(x<0 || x>=M || y<0 || y>=N)
        return;
    
    if(area[x][y] == 0){
        area[x][y] = area_cnt;
        areas[area_cnt]++;   
    }
    else
        return;
    for(int i=0; i<4; i++){
        temp_x = x; temp_y = y;
        fill_color(temp_x + to_x[i], temp_y + to_y[i]);
    }
}

void fill_area(){
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(area[i][j] != 0)
                continue;
            area_cnt++;
            fill_color(i, j);
        }
    }
    sort(areas+1, areas+area_cnt+1);
}

int main()
{
   input();
   fill_area();
   cout << area_cnt << "\n";
   for(int i=1; i<=area_cnt; i++)
    cout << areas[i] << " ";
   return 0;
}