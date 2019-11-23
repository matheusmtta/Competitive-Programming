/*
* Tempo do Duende
* URI Online Judge 2717
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int x, y, z;
  cin >> x >> y >> z;
  (y+z) <= x ? cout << "Farei hoje!" << endl : cout << "Deixa para amanha!" << endl;
  return 0;
}
