/*
* Máquina de Café
* URI Online Judge 2670
* 23/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, y, z;
  cin >> x >> y >> z;
  int aux[3];
  aux[0] = (2*y)+(4*z);
  aux[1] = (2*x)+(2*z);
  aux[2] = (4*x)+(2*y);
  sort(aux, aux+3);
  cout << aux[0] << endl;
  return 0;
}
