#include <stdio.h>
#include <algorithm>

using namespace std;

int dna[50][4] = {0};
char dna_char[4] = {'A','C','G','T'};
int N,M,i,j,ans2=0;
char ans1[50];
char input[50];

void get_dna(){
    int idx;
    for(i=0; i<M; i++){
        idx = max_element(dna[i], dna[i]+4) - dna[i];
        ans1[i] = dna_char[idx];
        ans2 += N-dna[i][idx];
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++){
        scanf("%s", input);
        for(j=0; j<M; j++){
            switch(input[j]){
            case 'A':
                dna[j][0]++;
                break;
            case 'C':
                dna[j][1]++;
                break;
            case 'G':
                dna[j][2]++;
                break;
            default:
                dna[j][3]++;
                break;
            }
        }
    }

    get_dna();
    printf("%s\n%d", ans1, ans2);
    return 0;
}
