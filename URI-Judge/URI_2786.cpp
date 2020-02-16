#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, t1, t2;
  cin >> n >> m;
  t1 = (n*m)+((n-1)*(m-1));
  t2 = (2*(n-1))+(2*(m-1));
  cout << t1 << endl;
  cout << t2 << endl;
  return 0;
}
