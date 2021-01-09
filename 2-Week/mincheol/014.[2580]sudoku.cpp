#include <stdio.h>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

typedef struct{int x,y;}coo;
int arr[9][9],rowi=0,coli=0,_in,endi;
int isend=0;
vector<coo> blanks;

void dfs(int idx, set<int>* row, set<int>* col, set<int>* block){
    int r=blanks[idx].x, c=blanks[idx].y;
    for(int i=1; i<10; i++){
        if( row[r].find(i)!=row[r].end() ) continue;
        if( col[c].find(i)!=col[c].end() ) continue;
        if( block[(r/3)*3+(c/3)].find(i)!=block[(r/3)*3+(c/3)].end() ) continue;

        arr[r][c] = i;
        if( endi==1 ) return;

        row[r].insert(i);
        col[c].insert(i);
        block[(r/3)*3+(c/3)].insert(i);
        endi--;

        dfs(idx+1, row, col, block);
        if( endi==1 ) return;

        row[r].erase(i);
        col[c].erase(i);
        block[(r/3)*3+(c/3)].erase(i);
    }
    endi++;
}

int main(){
    set<int> row[9], col[9], block[9];
    ifstream in("test.txt");
    if( in.is_open() ){
        for(int i=0; i<81; i++){
            in>>_in;
            arr[rowi][coli] = _in;
            row[rowi].insert(_in);
            col[coli].insert(_in);
            block[(rowi/3)*3+(coli/3)].insert(_in);
            if( _in==0 ){
                blanks.push_back({rowi,coli});
            }
            coli++;
            if( coli==9 ){
                rowi++;
                coli=0;
            }
        }
    }

    endi = blanks.size();
    dfs(0, row, col, block);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}
