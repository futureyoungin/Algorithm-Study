#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char bin_tree[1000];
int N;
int max_index=0;
string preorder="", inorder="", postorder="";

int find_char_index(char INPUT){
    int c_index=0;
    for(int i=1; i<=N*N; i++){    // 최대 N * N
        if(bin_tree[i] == INPUT){
            c_index = i;
            break;
        }
    }
    return c_index;
}

void input(){
    bin_tree[1] = 'A';
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    char root, left, right;
    int in_index;
    for(int i=0; i<N; i++){
        cin >> root >> left >> right;
        in_index = find_char_index(root);
        bin_tree[2*in_index] = left;
        bin_tree[2*in_index+1] = right;
        max_index = max(max_index, 2*in_index+1);
    }
}

void print_pre(int node){
    if(node > max_index)
        return;
    
    if(bin_tree[node] >= 'A' && bin_tree[node] <= 'Z')
        preorder += bin_tree[node];
    else
        return;
    print_pre(node*2);
    print_pre(node*2+1);
}

void print_in(int node){
    if(node > max_index)
        return;
    
    print_in(node*2);
    if(bin_tree[node] >= 'A' && bin_tree[node] <= 'Z')
        inorder += bin_tree[node];
    else
        return;
    print_in(node*2+1);
}

void print_post(int node){
    if(node > max_index)
        return;
    
    print_post(node*2);
    print_post(node*2+1);
    if(bin_tree[node] >= 'A' && bin_tree[node] <= 'Z')
        postorder += bin_tree[node];
    else
        return;
}

int main(){
    input();
    print_pre(1); print_in(1); print_post(1);
    cout << preorder << "\n" << inorder << "\n" << postorder;
    return 0;
}