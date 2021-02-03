#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;



int V, E;
int group[10001];

bool compare(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b){
    return a.first < b.first;
}
priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    int A,B,C;
    for(int i=0; i<E; i++){
        cin >> A >> B >> C;
        pq.push(make_pair(C, make_pair(A,B)));
    }
    for(int i=1; i<=V; i++)
        group[i] = i;
}    

int where_in(int ver){
    if(group[ver] == ver)
        return ver;
    return where_in(group[ver]);
}

int MST(){
    int sum=0;
    int n_edge=0;
    int A,B,C;
    int team_A, team_B;
    while(n_edge != V-1){
        A = pq.top().second.first, B=pq.top().second.second;
        C = pq.top().first;
        pq.pop();
        team_A = where_in(A); team_B = where_in(B);
        if(team_A == team_B)
            continue;
        else{
            sum += C;
            if(team_A < team_B)
                group[team_B] = team_A;
            else
                group[team_A] = team_B;
            n_edge++;
        }
    }
    return sum;
}

int main(){
    input();
    cout << MST();
    return 0;
}