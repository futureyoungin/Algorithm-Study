#include <iostream>

using namespace std;

struct Node{
	char left, right;
};

Node tree[27];

void Input(){
	int N;
	char value, left, right;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> value >> left >> right;
		tree[value].left = left;
		tree[value].right = right;
	}
}

void preorder(char root){
	if(root == '.') return;
	cout << root;
	preorder(tree[root].left);
	preorder(tree[root].right);
}

void inorder(char root){
	if(root == '.') return;
	inorder(tree[root].left);
	cout << root;
	inorder(tree[root].right);
}

void postorder(char root){
	if(root == '.') return;
	postorder(tree[root].left);
	postorder(tree[root].right);
	cout << root;
}

void Solve(){
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";
}

int main(){

	Input();
	Solve();
	
	return 0;
}