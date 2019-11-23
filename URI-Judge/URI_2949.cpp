/*
* A Sociedade do Anel
* URI Online Judge 2949
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int hobbit, humano, elfo, anao, magos;

int main(){
  int n;
  string a;
  char aux;
  cin >> n;
  getchar();
  while(n--){
    cin >> a;
    cin >> aux;
    if (aux == 'X') hobbit++;
    else if (aux == 'A') anao++;
    else if (aux== 'E') elfo++;
    else if (aux == 'H') humano++;
    else if (aux == 'M') magos++;
  }
    cout << hobbit << " Hobbit(s)" << endl;
    cout << humano << " Humano(s)" << endl;
    cout << elfo << " Elfo(s)" << endl;
    cout << anao << " Anao(s)" << endl;
    cout << magos << " Mago(s)" << endl;
}
