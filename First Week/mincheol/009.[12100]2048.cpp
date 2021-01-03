#include <iostream>
#include <vector>

// Brute force
// O(n^2)

using namespace std;

int lines;
int stx[]={0,0,0,0}, sty[]={0,0,0,0};
typedef struct {int x,y;}coord;

coord moves(coord a, int i){
    switch(i){
    case 0:
        a.x++;
        break;
    case 1:
        a.x--;
        break;
    case 2:
        a.y++;
        break;
    case 3:
        a.y--;
        break;
    default: break;
    }
    return a;
}

int dfs(int dep, vector<vector<int>> arr, int maxi){
    for(int i=0; i<4; i++){
        vector<vector<int>> vtmp(lines, vector<int>(lines,0));
        coord st;
        st.x = stx[i], st.y = sty[i];
        int isch = 0;
        for(int one=0; one<lines; one++){
            coord iter = st;    // 1줄 이동하며 확인
            coord blank = st;   // 이동되거나 합쳐질 위치. 합쳐지면 한칸이동
            for(int two=0; two<lines; two++){
                if( arr[iter.x][iter.y]!=0 ){
                    // 합쳐짐
                    if( arr[iter.x][iter.y]==vtmp[blank.x][blank.y] ){
                        vtmp[blank.x][blank.y] *= 2;
                        if( maxi<vtmp[blank.x][blank.y] ) maxi = vtmp[blank.x][blank.y];
                        blank = moves(blank, i);
                        isch = 1;
                    }else{
                        if( vtmp[blank.x][blank.y]==0 ){
                            vtmp[blank.x][blank.y] = arr[iter.x][iter.y];
                            if( blank.x!=iter.x || blank.y!=iter.y ) isch = 1;
                        }else if( arr[iter.x][iter.y]!=0 ){
                            blank = moves(blank, i);
                            vtmp[blank.x][blank.y] = arr[iter.x][iter.y];
                            if( blank.x!=iter.x || blank.y!=iter.y ) isch = 1;
                        }
                    }
                }
                iter = moves(iter, i);
            }
            st = moves(st, 2-2*(i/2));  // i=0,1 -> 아래쪽 이동
                                        // i=2,3 -> 오른쪽 이동
        }
        if( isch ){
            if( dep<5 ){
                int tmp = dfs(dep+1, vtmp, maxi);
                if( maxi<tmp ) maxi = tmp;
            }
        }
    }
    return maxi;
}

int main(){
    cin>>lines;
    vector<vector<int>> arr(lines);
    int maxi=0;
    stx[1] = lines-1, sty[3] = lines-1;
    for(int i=0; i<lines; i++){
        for(int j=0; j<lines; j++){
            int num;
            cin>>num;
            if( num>maxi ) maxi = num;
            arr[i].push_back(num);
        }
    }
    cout<<dfs(1, arr, maxi);
    return 0;
}
