#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
	int name;
	int recommend;
	int idx;
	Student(int name, int recommend, int idx){
		this-> name = name; this -> recommend = recommend; this -> idx = idx;
	}
};

bool comp(Student a, Student b){
	return a.name < b.name;
}

//O(K*N)


int main() {
	int N, K;
	cin >> N >> K;
	vector<Student> v;

	for(int i=0;i<K;i++){
		int s;
		bool flag = false;
		cin >> s;

		for(int j=0;j<v.size();j++){
			if(v[j].name == s){
				v[j].recommend += 1;
				flag = true;
			}
		}

		if(!flag){
			if(v.size()<N){
				v.push_back(Student(s, 1, i));
			}else{
				Student tmp = Student(1001, 1001, 1001); int tmp_l = 1001;
				for(int l = 0; l<v.size(); l++){
					if(tmp.recommend > v[l].recommend){
						tmp = v[l]; tmp_l = l;
					}else if(tmp.recommend == v[l].recommend && tmp.idx > v[l].idx){
						tmp = v[l]; tmp_l = l;
					}
				}
				v[tmp_l] = Student(s, 1, i);
			}
		}
	}

	sort(v.begin(), v.end(), comp);

	for(int i=0;i<v.size();i++){
		cout << v[i].name << " ";
	}
	cout << "\n";

}
