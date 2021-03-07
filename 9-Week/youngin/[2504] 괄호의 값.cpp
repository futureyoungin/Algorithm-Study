#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>

using namespace std;

string s_input;
stack<string> st;
bool success = true;

int pair_a_first=0;
int pair_a_second=-0;

int pair_b_first=0;
int pair_b_second=0;

void solve(char input){
    if(!success)
        return;
        
    string pop_st="";
    int mul_integer=0;
    
    if(input == ')'){
        pair_a_second++;
        while(pop_st != "("){
            if(st.empty()){
                success = false;
                st.push("0");
                return;
            }
            
            pop_st = st.top();
            st.pop();
            
            if(pop_st == "["){
                success = false;
                st.push("0");
                return;
            }
            
            else if(pop_st == "("){
                if(mul_integer == 0){
                    st.push("2");
                }
                else{
                    mul_integer = mul_integer *2;
                    st.push(to_string(mul_integer));
                }
            }
            else{
                mul_integer += stoi(pop_st);
            }
            
        }
    }
    else if(input == ']'){
        pair_b_second++;
        while(pop_st != "["){
            if(st.empty()){
                success = false;
                st.push("0");
                return;
            }
            pop_st = st.top();
            st.pop();
            if(pop_st == "("){
                success = false;
                st.push("0");
                return;
            }
            else if(pop_st == "["){
                if(mul_integer == 0){
                    st.push("3");
                }
                else{
                    mul_integer = mul_integer *3;
                    st.push(to_string(mul_integer));
                }
            }
            else{
                mul_integer += stoi(pop_st);
            }
        }
    }
    else{
        if(input == '(')
            pair_a_first++;
        else if(input == '[')
            pair_b_first++;
        
        string temp = "";
        temp += input;
        st.push(temp);
    }
}

int main()
{
    cin >> s_input;
    for(int i=0; i<s_input.length(); i++){
        solve(s_input[i]);

    }
    int result = 0;
    if(!success){
        cout << 0;
    }
    else if(pair_a_first != pair_a_second || pair_b_first != pair_b_second){
        cout << 0;
    }
    
    else if(st.size() == 1){
        cout << st.top();
    }
    else if(st.size() > 1){
        string temp;
        while(st.size() != 0){
            temp = st.top();
            st.pop();
            result += stoi(temp);
        }
        cout << result;
    }
    
    
    return 0;
}