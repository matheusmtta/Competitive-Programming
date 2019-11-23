/*
* TCC da Depressão Natalina
* URI Online Judge 2930
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, y;
  cin >> x >> y;
  if (x > y) {cout << "Eu odeio a professora!" << endl; exit(0);}
  if ((y-x)>=3) {cout << "Muito bem! Apresenta antes do Natal!" << endl; exit(0);}
  else cout << "Parece o trabalho do meu filho!" << endl;
  if (y+2 < 25) cout << "TCC Apresentado!" << endl;
  else cout << "Fail! Entao eh nataaaaal!" << endl;
  return 0;
}
