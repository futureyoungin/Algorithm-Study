#include <iostream>
typedef long long ll;

using namespace std;

ll calculate(int n, int m){
	int ans = 0;
	for(ll i = m; n/i>=1; i*=m){
		ans += n/i;
	}

	return ans;
}

int main(){
	int n, m;
	cin >> n >> m;

	int calc_two = calculate(n, 2) - calculate(n-m, 2) - calculate(m, 2);
	int calc_five = calculate(n, 5) - calculate(n-m, 5) - calculate(m, 5);
	cout << min(calc_five, calc_two) << "\n";

}
