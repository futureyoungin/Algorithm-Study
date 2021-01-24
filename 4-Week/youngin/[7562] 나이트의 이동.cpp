#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int T, I;
int cur_loc_x, cur_loc_y;
int to_loc_x, to_loc_y;
int visit[310][310] ={0, };
queue<pair<pair<int,int>, int>> q;  // x, y, distance

int to_x[8] ={1, 2, 2, 1, -1, -2, -2, -1};
int to_y[8] ={2, 1, -1, -2, -2, -1, 1, 2};

bool in_range(int x, int y){
	if( x>=0 && x<I && y>=0 && y<I)
		return true;
	return false;
}

int bfs(){
	int loc_x=cur_loc_x, loc_y=cur_loc_y;
    int temp_loc_x, temp_loc_y;
	int distance =0;
	q.push(make_pair(make_pair(cur_loc_x, cur_loc_y), 0));
	while( !((loc_x==to_loc_x)&&(loc_y==to_loc_y)) ){
		loc_x = q.front().first.first, loc_y = q.front().first.second;       
		distance = q.front().second;
		q.pop();
		for(int i=0; i<8; i++){
            temp_loc_x = loc_x, temp_loc_y = loc_y;
			temp_loc_x += to_x[i], temp_loc_y += to_y[i];
			if(in_range(temp_loc_x, temp_loc_y)){
				if(visit[temp_loc_x][temp_loc_y] == 0){
					q.push(make_pair(make_pair(temp_loc_x, temp_loc_y), distance+1) );
					visit[temp_loc_x][temp_loc_y] = 1;
				}
			}
		}
	}
	while(!q.empty()){
        q.pop();
    }
	memset(visit, 0, sizeof(int)*310*310);
	return distance;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> I;
		cin >> cur_loc_x >> cur_loc_y;
		cin >> to_loc_x >> to_loc_y;
		cout << bfs() << "\n";
	}
	return 0;
}