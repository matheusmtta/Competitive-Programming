/*
* Lendo Livros
* URI Online Judge 1542
* 24/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

using namespace std;


int main(){
  int p=1, d=1, q=1, x=0;
  while(1){
    cin >> q;
    if (!q) break;
    cin >> d >> p;
    x = (p*d*q)/(p-q);
    if (x > 1)
      cout << x << " paginas" << endl;
    else cout << x << " pagina" << endl;
  }
  return 0;
}
