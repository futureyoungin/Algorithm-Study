#include <iostream>
#include <fstream>

using namespace std;

int lines,nums,T,turn_num,dir,can,all_nums,all_sum=0;
int boards[50][50];
int turn_save[50];

void turn(){
    if( !dir ) can *= -1;
    for(int j=turn_num; j<=lines; j+=turn_num){
        for(int i=0; i<nums; i++){
            turn_save[i] = boards[j-1][i];
        }
        for(int i=0; i<nums; i++){
            boards[j-1][i] = turn_save[(i+can+nums)%nums];
        }
    }
}

bool del(){
    bool isch=false;
    for(int i=0; i<lines; i++){
        for(int j=0; j<nums; j++){
            if( boards[i][j]!=0 ){
                if( j==nums-1 ){
                    if( abs(boards[i][j])==abs(boards[i][0]) ){
                        boards[i][j] = -abs(boards[i][j]);
                        boards[i][0] = -abs(boards[i][0]);
                    }
                }else{
                    if( abs(boards[i][j])==abs(boards[i][j+1]) ){
                        boards[i][j] = -abs(boards[i][j]);
                        boards[i][j+1] = -abs(boards[i][j+1]);
                    }
                }

                if( i!=lines-1 ){
                    if( abs(boards[i][j])==abs(boards[i+1][j]) ){
                        boards[i][j] = -abs(boards[i][j]);
                        boards[i+1][j] = -abs(boards[i+1][j]);
                    }
                }
            }
        }
    }
    for(int i=0; i<lines; i++){
        for(int j=0; j<nums; j++){
            if( boards[i][j]<0 ){
                all_sum += boards[i][j];
                all_nums--;
                boards[i][j] = 0;
                isch = true;
            }
        }
    }
    return isch;
}

void solution(){
    turn();
    if( !(del()) ){
        float sum = all_sum/(float)all_nums;
        //cout<<all_sum<<" "<<all_nums<<" "<<sum<<"\n";
        for(int i=0; i<lines; i++){
            for(int j=0; j<nums; j++){
                if( boards[i][j]!=0 ){
                    if( boards[i][j]>sum ){
                        boards[i][j]--;
                        all_sum--;
                    }else if( boards[i][j]<sum ){
                        boards[i][j]++;
                        all_sum++;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    cin>>lines>>nums>>T;
    all_nums = lines*nums;
    for(int i=0; i<lines; i++){
        for(int j=0; j<nums; j++){
            cin>>boards[i][j];
            all_sum += boards[i][j];
        }
    }
    for(int i=0; i<T; i++){
        cin>>turn_num>>dir>>can;
        solution();
    }*/
    ifstream in("test.txt");
    if( in.is_open() ){
        in>>lines>>nums>>T;
        all_nums = lines*nums;
        for(int i=0; i<lines; i++){
            for(int j=0; j<nums; j++){
                in>>boards[i][j];
                all_sum += boards[i][j];
            }
        }
        for(int i=0; i<T; i++){
            in>>turn_num>>dir>>can;
            solution();
            for(int k=0; k<lines; k++){
                for(int j=0; j<nums; j++){
                    cout<<boards[k][j]<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
    }
    cout<<all_sum<<"\n";
    return 0;
}
