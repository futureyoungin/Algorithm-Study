#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, T;
int tree[10010]={0, };
int min_level = -1;

void solution();


void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
}

void solve(){
    for(int i=0; i<T; i++){
        cin >> N;
        for(int j=0; j<N; j++)
            cin >> tree[j];
        solution();
        memset(tree, 0, sizeof(int)*N);
        min_level = -1;
    }
}

void solution(){
    sort(tree, tree+N);
    int *temp_array = new int[N];
    temp_array[0] = tree[0];
    int a_point = 1, b_point = N-1;
    int tree_a_point = 1;
    int tree_b_point = 2;
    while(a_point <= b_point){
        if(a_point == b_point){
            temp_array[a_point] = tree[tree_a_point];
            a_point++; b_point--;
            tree_a_point += 2;
            tree_b_point += 2;
            continue;
        }
        
        temp_array[a_point] = tree[tree_a_point];
        temp_array[b_point] = tree[tree_b_point];
        a_point++; b_point--;
        tree_a_point += 2;
        tree_b_point += 2;
    }
    
    for(int i=0; i<N; i++){
        min_level = max(min_level, abs(temp_array[i]-temp_array[(i+1)%N]));
    }
    cout << min_level << "\n";
    delete[] temp_array;
}

int main()
{
    input();
    solve();
    
    return 0;
}