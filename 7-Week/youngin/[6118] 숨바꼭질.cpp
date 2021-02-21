#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>


using namespace std;

#define MAX_N 20001

int N, M;
int max_length=0;
vector<int> edge[MAX_N];
vector<int> houses[MAX_N]; // length마다 houses.
queue<pair<int, int>> q;
bool visit[MAX_N]={false, };

void input(){
    int temp_a, temp_b;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> temp_a >> temp_b;
        edge[temp_a].push_back(temp_b);
        edge[temp_b].push_back(temp_a);
    }
}

void bfs(){
    int house, dis, v_house;
    q.push(make_pair(1, 0));
    visit[1]=true;
    while(!q.empty()){
        house = q.front().first, dis = q.front().second;
        q.pop();
        dis++;
        for(int i=0; i<edge[house].size(); i++){
            v_house = edge[house][i];
            if(visit[v_house]) continue;
            if(max_length < dis){
                houses[max_length].clear();
                max_length = dis;
            }
            //cout << v_house << " ";
            q.push(make_pair(v_house, dis));
            houses[dis].push_back(v_house);
            visit[v_house] = true;
        }
        //cout << "\n";
    }
}

int main()
{
   input();
   bfs();
   sort(houses[max_length].begin(), houses[max_length].end());
   cout << houses[max_length][0] << " " << max_length << " " << houses[max_length].size();
   return 0;
}