#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int arr[1000][3];

int main(){
    scanf("%d", &N);
    scanf("%d %d %d", &arr[0][0], &arr[0][1], &arr[0][2]);
    for(int i=1; i<N; i++){
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
        arr[i][0] += min(arr[i-1][1], arr[i-1][2]);
        arr[i][1] += min(arr[i-1][0], arr[i-1][2]);
        arr[i][2] += min(arr[i-1][0], arr[i-1][1]);
    }
    printf("%d\n", *min_element(arr[N-1], arr[N-1]+3));
    return 0;
}
