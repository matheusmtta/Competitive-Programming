#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, ub, lb, sum=0, x;
  while (cin >> n >> ub >> lb){
    for (int i = 0; i < n; i++){
      cin >> x;
      if (x >= ub && x <= lb) sum++;
    }
    cout << sum << endl;
    sum=0;
  }
  return 0;
}
