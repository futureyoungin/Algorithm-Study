#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX_L 100001

int N, K, seconds;
int *result;
int visit[MAX_L] = {0, };

queue<pair<int*, pair<int, int>>> q_bfs; // <route, <level, current value>>

void bfs(){
    int *temp = new int[1];
    temp[0] = N;
    q_bfs.push(make_pair(temp, make_pair(0, N)));
    visit[N] = 1;
    int *route = nullptr;
    int level;
    int current_value;
    while(!q_bfs.empty()){
        route = q_bfs.front().first;
        level = q_bfs.front().second.first, current_value = q_bfs.front().second.second;
        q_bfs.pop();
        if(current_value == K)
            break;
        int *route1, *route2, *route3;
        if(current_value>0 && visit[current_value-1] == 0){           
            route1 = new int[level+1];
            copy(&route[0], &route[0] + level, &route1[0]);
            route1[level] = current_value -1;
             if(current_value-1 == K){
                 result = route1;
                 seconds = level+1;
                 return;
             }
            q_bfs.push(make_pair(route1, make_pair(level+1, current_value-1)));
            visit[current_value-1] = 1;
        }
        if(visit[current_value+1] == 0){
            route2 = new int[level+1];
            copy(&route[0], &route[0] + level, &route2[0]);
            route2[level] = current_value +1;
            if(current_value+1 == K){
                 result = route2;
                 seconds = level+1;
                 return;
             }
            q_bfs.push(make_pair(route2, make_pair(level+1, current_value+1)));
            visit[current_value+1] = 1;
        }
        if(current_value*2 < MAX_L && visit[current_value*2] == 0){
            route3 = new int[level+1];
            copy(&route[0], &route[0] + level, &route3[0]);
            route3[level] = current_value *2;
            if(current_value*2 == K){
                 result = route3;
                 seconds = level+1;
                 return;
             }
            q_bfs.push(make_pair(route3, make_pair(level+1, current_value*2)));
            visit[current_value*2] = 1;
        }
        delete[] route;
    }
    result = route;
    seconds = level;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    if(N<=K){
    bfs();
    cout << seconds << "\n";
    cout << N << " ";
    for(int i=0; i<seconds; i++)
        cout << result[i] << " ";
    }
    
    else{
        cout << N-K << "\n";
        for(int i=N; i>=K; i--)
            cout << i << " ";
    }
    return 0;
}