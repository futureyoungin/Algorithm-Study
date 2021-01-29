#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line{
	int weight, start, end;
	line(int weight, int start, int end){
		this->weight = weight;
		this->start = start;
		this->end = end;
	}
};

bool comp(line a, line b){
	return a.weight < b.weight;
}

int parent_check(int parent[10001], int node){
	if(parent[node]==node)	return node;
	return parent[node] = parent_check(parent, parent[node]);
}

void same_parent(int parent[10001], int a, int b){
	parent[parent[a]] = parent[b];
}

int main(){
	int V, E, a, b, c, total = 0;
	vector<line> v;
	int parent[10001] = {0};

	cin >> V >> E;
	for(int i=0;i<E;i++){
		cin >> a >> b >> c;
		v.push_back(line(c, a, b));
	}

	sort(v.begin(), v.end(), comp);

	for(int i=0;i<V;i++){
		parent[i] = i;
	}

	for(int i=0;i<v.size();i++){
		line now = v[i];
		if(parent_check(parent, now.start) != parent_check(parent, now.end)){
			total += now.weight;
			same_parent(parent, now.start, now.end);
		}
	}

	cout << total << "\n";

	return 0;
}
