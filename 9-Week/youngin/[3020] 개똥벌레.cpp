#include <iostream>
#include <algorithm>

using namespace std;

int N, H;
int bot_cave[500500]={0, };
int top_cave[500500]={0, };
int ruin_sum[500050] ={0, };
int min_ruin=2000300;
int cnt=0;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> H;
    int temp_h1, temp_h2;
    for(int i=0; i<N/2; i++){
        cin >> temp_h1 >> temp_h2;
        bot_cave[temp_h1]++;
        top_cave[temp_h2]++;
    }
}



void solve(){
    for(int i=1; i<=H; i++){
        bot_cave[H-i] += bot_cave[H-i+1];
        top_cave[H-i] += top_cave[H-i+1];
    }
    
    ruin_sum[1] = bot_cave[1];
    ruin_sum[H] = top_cave[1];
    for(int i=2; i<=H; i++){
        ruin_sum[i] = bot_cave[i] + top_cave[H-i+1];
    }
    sort(ruin_sum+1, ruin_sum+H+1);
}

int main()
{
    input();
    solve();
    cout << ruin_sum[1] << " ";
    int cnt=0;
    for(int i=1; i<=H; i++){
        if(ruin_sum[i] != ruin_sum[1])
            break;
        cnt++;
    }
    
    cout << cnt;
    return 0;
}