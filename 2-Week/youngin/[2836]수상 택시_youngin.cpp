#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>

#define MAX(a,b) a>b? a:b

using namespace std;

int n, m;

unsigned long long total_distance = 0;
vector<pair<unsigned long long, unsigned long long>> back_person;


void input() {
	cin >> n >> m;
	int start, end;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		if (end < start)
			back_person.push_back(make_pair(end, start));
	}
	sort(back_person.begin(), back_person.end());
}



unsigned long long sweeping() {
	vector<pair<unsigned long long,unsigned long long>>::iterator iter;
    unsigned long long p_a = back_person.begin()->first, p_b=back_person.begin()->second;
    for(iter = back_person.begin(); iter != back_person.end(); iter++){
        if(p_b < iter->first){                // not overlap
            total_distance += (p_b-p_a)*2;
            p_a = iter->first, p_b = iter->second;
        }
        else{          // overlap          
            p_b = MAX(p_b, iter->second);
        }
    }
    total_distance += (p_b-p_a)*2;
    return total_distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	input();
	total_distance += m; // people do not go to back.
	cout << sweeping();
	return 0;
}