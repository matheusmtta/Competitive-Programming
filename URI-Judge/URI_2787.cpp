/*
* Xadrez
* URI Online Judge 2787
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, y;
  cin >> x >> y;
  if ((x%2==0 && y%2==0) || (x%2==1 && y%2==1)) cout << 1 << endl;
  else cout << 0 << endl;
}
