/*
* Dividindo Círculos
* URI Online Judge 2802
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  unsigned long long int n, f;
  cin >> n;
  f = ((n*(n-1)*(n-2)*(n-3))/24)+(((n-1)*n)/2)+1;
  cout << f << endl;
  return 0;
}
