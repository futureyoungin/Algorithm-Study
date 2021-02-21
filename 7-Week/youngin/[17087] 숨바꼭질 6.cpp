#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, S;
int max_dis;
int bro[100000]={0,};
int bro_minus[100000]={0,};


void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;
    for(int i=0; i<N; i++)
        cin >> bro[i];
    for(int i=0; i<N; i++)
        bro_minus[i] = abs(bro[i]-S);
    sort(bro_minus, bro_minus+N);
}

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void find_max(){
    max_dis = bro_minus[0];
    for(int i=1; i<N; i++){
        max_dis = gcd(max_dis, bro_minus[i]);
    }
}

int main()
{
    input();
    find_max();
    cout << max_dis;
   return 0;
}