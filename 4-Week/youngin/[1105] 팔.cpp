#include <iostream>
#include <string>

using namespace std;
string L, R;

int main(){
    int cnt=0;
    cin >> L >> R;
    if(L.length() != R.length()){
        cout << 0;
        return 0;
    }
    else{
        for(int i=0; i<L.length(); i++){
            if(L[i] != R[i])
                break;
            if(L[i] == R[i] && L[i] == '8')
                cnt++;
        }
        cout << cnt;
    }
    return 0;
}