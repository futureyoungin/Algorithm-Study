#include <iostream>
#include <string.h>
#define MAXSIZE

using namespace std;

int main(void){
	int R,C,T, up, down;
	scanf("%d %d %d", &R, &C, &T);
	int map[R][C] = {0}, tmp_map[R][C] = {0};
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> map[i][j];
			if (map[i][j]==-1) {down = i; up = i-1;}
		}
	}
	for(int t=0;t<T;t++){
		//미세먼지 확산
		memset(tmp_map, 0, sizeof(tmp_map));
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				int current_dust = map[i][j];
				int next_dust = current_dust/5;
				if(i>0 && map[i-1][j] != -1){tmp_map[i-1][j]+= next_dust; map[i][j] -= next_dust;} 
				if(i<R-1 && map[i+1][j] != -1){tmp_map[i+1][j]+= next_dust; map[i][j] -= next_dust;} 
				if(j>0 && map[i][j-1] != -1){tmp_map[i][j-1]+= next_dust; map[i][j] -= next_dust;} 
				if(j<C-1 && map[i][j+1] != -1){tmp_map[i][j+1]+= next_dust; map[i][j] -= next_dust;} 
			}
		}

		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				map[i][j]+=tmp_map[i][j];

		//공기청정기 작동
		//up
		for(int i=up-1; i>=1; i--)
			map[i][0] = map[i-1][0];
		for(int i=0; i<C-1; i++)
			map[0][i] = map[0][i+1];
		for(int i=0; i<up; i++)
			map[i][C-1] = map[i+1][C-1];
		for(int i=C-1; i>=1; i--)
			map[up][i] = map[up][i-1];
		map[up][1] = 0;

		//down
		for(int i=down+1; i<R-1; i++)
			map[i][0] = map[i+1][0];
		for(int i=0; i<C-1; i++)
			map[R-1][i] = map[R-1][i+1];
		for(int i=R-1; i>down; i--)
			map[i][C-1] = map[i-1][C-1];
		for(int i=C-1; i>=1; i--)
			map[down][i] = map[down][i-1];
		map[down][1] = 0;
	}
	int total = 2;
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			total+= map[i][j];
	
	printf("%d\n", total);
}