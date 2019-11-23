/*
* Packing for Holiday
* Uva Online Judge 12372
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  int k = 1;
  while(n--){
    int x, y, z;
    cin >> x >> y >> z;
    printf("Case %d:", k);
    if (x <= 20 && y <= 20 && z <= 20)
      cout << " good" << endl;
    else cout << " bad" << endl;
    k++;
  }
  return 0;
}
