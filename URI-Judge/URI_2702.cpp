/*
* Escolha Difícil
* URI Online Judge 2702
* 25/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

using namespace std;


int main(){
  int x, y, z, ans=0;
  int x1, y1, z1;
  cin >> x >> y >> z;
  cin >> x1 >> y1 >> z1;
  if (x1-x > 0) ans+=(x1-x);
  if (y1-y > 0) ans+=(y1-y);
  if (z1-z > 0) ans+=(z1-z);
  cout << ans << endl;
  return 0;
}
