/*
* Papagaio Poliglota
* URI Online Judge 2850
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  string a;
  while(getline(cin, a)){
    if (a == "esquerda") cout << "ingles" << endl;
    else if (a == "direita") cout << "frances" << endl;
    else if (a == "nenhuma") cout << "portugues" << endl;
    else cout << "caiu" << endl;
  }
}
