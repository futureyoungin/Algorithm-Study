#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int min_length=200000001;
int n_array[100010];

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;
    for(int i=0; i<N; i++){
        cin >> n_array[i];
        
    }
}

void two_pointer(){
    int start=0, end=0;
    int sum=0;
    while(start <= end){
        if(sum < S){
            if(end>N-1)
                break;
            sum += n_array[end++];
        }
        else if(sum >= S){
            min_length = min(min_length, end-start);
            sum -= n_array[start++];
        }
        
    }
}

int main(){
    input();
    two_pointer();
    if(min_length == 200000001)
        cout << 0;
    else
        cout << min_length;
    
    return 0;
}