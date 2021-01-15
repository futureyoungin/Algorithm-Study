#include <iostream>
#include <algorithm>

using namespace std;

int n, c;
int houses[200000] ={0, };
int max_distance = 0;

void input(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n >> c;
  for(int i=0; i<n; i++)
    cin >> houses[i];
  sort(houses, houses+n);
}


bool possible_distance(int distance){
  bool ret = false;
  int n_wifi = 1;
  int before_house = houses[0];
  for(int i=1; i<n; i++){
    if((houses[i] - before_house) >= distance){
      n_wifi++;
      before_house = houses[i];
    }
  }
  if(n_wifi >= c)
    ret = true;
  return ret;
}

void searching(){
  int left, right, mid;
  bool ret;
  left = 0; right = houses[n-1]-houses[0]; 
  while(left<=right){
    mid = (left+right)/2;
    ret = possible_distance(mid);
    if(ret){
      left = mid+1;
      if(max_distance < mid)
        max_distance = mid;
    }
    else{
      right = mid-1;
    }
  }
}

int main() {
  input();
  searching();
  cout << max_distance;
  return 0;
}