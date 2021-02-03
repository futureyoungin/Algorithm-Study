#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_L 100000

int N, K, B;
int signal[MAX_L]={0, };
int part_sum[MAX_L]={0,}; // part_sum[a] : a~a+k 까지 broken 수.

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int broken;
    cin >> N >> K >> B;
    for(int i=0; i<B; i++){
        cin >> broken;
        signal[broken-1] = 1;
    }
    for(int i=0; i<=N-K; i++){
        int p_sum =0;
        for(int j=i; j<i+K; j++){
            if(signal[j] == 1)
                p_sum++;
        }
        part_sum[i] = p_sum;
    }
}

int main(){
    input();
    int minimum = 100000000;
    for(int i=0; i<=N-K; i++){
        minimum = min(minimum, part_sum[i]);
    }
    cout << minimum;
    return 0;
}