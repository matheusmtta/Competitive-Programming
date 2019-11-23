/*
* The Snail
* UVa Online Judge 00573
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  while (1){
    double h, u, d, f;
    cin >> h >> u >> d >> f;
    if (h==0) return 0;
    double x = 0;
    int days=0;
    f=u*(f/100.0);
    while (1){
      days++;
      x+=u;
      u-=f;
      if (u < 0) u = 0;
      if (x > h) break;
      x-=d;
      if (x < 0) break;
    }
    if (x <= 0) cout << "failure on day " << days << endl;
    else cout << "success on day " << days << endl;
  }
  return 0;
}
