#include <iostream>
#include <algorithm>


using namespace std;


int L, C;
char alphabet[15];
bool print_idx[15]={false, };

bool check_m(char a){
    if(a == 'a' || a == 'e' || a =='i' || a == 'o' || a == 'u')
        return true;
    return false;
}

bool check_s(char a){
    if(a == 'a' || a == 'e' || a =='i' || a == 'o' || a == 'u')
        return false;
    return true;
}

void print(int start_idx, int cur_idx, int cnt, int m_cnt, int s_cnt){
    if(cnt==L){
        if(m_cnt <1 || s_cnt <2)
            return;
        
        for(int i=0; i<C; i++)
            if(print_idx[i])
                cout << alphabet[i];
        cout << "\n";
        return;
    }
    
    if(cur_idx >= C){
        return;
    }
    
    for(int i=cur_idx+1; i<C; i++){
        if(check_m(alphabet[i]))
            m_cnt++;
        
        if(check_s(alphabet[i]))
            s_cnt++;
        
        print_idx[i] = true;
        print(start_idx, i, cnt+1, m_cnt, s_cnt);
        print_idx[i] = false;
        
        if(check_m(alphabet[i]))
            m_cnt--;
        
        if(check_s(alphabet[i]))
            s_cnt--;
    }
}

void solve(){
    sort(alphabet, alphabet+C);
    int m_cnt=0;
    int s_cnt =0;
    for(int i=0; i<=C-L; i++){
        if(check_m(alphabet[i]))
            m_cnt++;
        if(check_s(alphabet[i]))
            s_cnt++;
    
        print_idx[i] = true;
        print(i, i, 1, m_cnt, s_cnt);    
        print_idx[i] = false;
        
        if(m_cnt)
            m_cnt--;
        if(s_cnt)
            s_cnt--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> L >> C;
    for(int i=0; i<C; i++)
        cin >> alphabet[i];
    
    solve();
    
    return 0;
}