#include <iostream>
#include <string>


using namespace std;

string origin;
string temp="";
int result=0;
bool cminus = false;


int main(){
    cin >> origin;
    for(int i=0; i<=origin.length(); i++){
        if(origin[i] == '+' || origin[i] == '-' || origin[i] == '\0'){
            if(cminus) result -= stoi(temp);
            else result += stoi(temp);
            temp = "";
            if(origin[i] == '-')
                cminus = true;
        }
        else
            temp += origin[i];      
    }
    cout << result;
    return 0;
}