#include <iostream>

using namespace std;

int N;
char MAP[7000][7000];


void solution(int n, int x, int y){
    if(n==1){
        MAP[x][y] = '*';
        return;
    }
    
    int div_n = n/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1 && j==1){
                continue;
            }
            else{
                solution(div_n, x+(div_n*i), y+(div_n*j));
            }
        }
    }
}

void solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            MAP[i][j] = ' ';
        }
    }
    
    solution(N, 0, 0);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << MAP[i][j];
        }
        cout << "\n";
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> N;
    solve();
    return 0;
}