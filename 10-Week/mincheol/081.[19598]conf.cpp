#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, ans=0;
pair<int,int> arr[100000];
priority_queue<int,vector<int>,greater<int> > pqu;

void solution(){
    sort(arr, arr+N);
    pqu.push(arr[0].second);
    for(int i=1; i<N; i++){
        while( !pqu.empty() && pqu.top()<=arr[i].first ) pqu.pop();
        pqu.push(arr[i].second);
        ans = max(ans, (int)pqu.size());
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    solution();
    return 0;
}
