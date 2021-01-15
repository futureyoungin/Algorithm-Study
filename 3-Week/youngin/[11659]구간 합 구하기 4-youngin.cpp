#include <iostream>

using namespace std;

int n, m;
int part_Sum[100010]= {0, };  // part_Sum[x] = 1 ~ x까지의 부분 합.

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int temp;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> temp;
        part_Sum[i+1] = part_Sum[i] + temp;        
    }
}

void part_sum(){
    int start, end;
    for(int i=0; i<m; i++){
        cin >> start >> end;
        cout << part_Sum[end] - part_Sum[start-1] << "\n";
    }
}

int main(){
    input();
    part_sum();
    return 0;
}