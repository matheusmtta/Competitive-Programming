/*
* A Mudança
* URI Online Judge 2685
* 23/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin >> n){
    if (n == 360 || (n>= 0 && n<90)) cout << "Bom Dia!!" << endl;
    else if (n>=90 && n<180) cout << "Boa Tarde!!" << endl;
    else if (n>=180 && n<270) cout << "Boa Noite!!" << endl;
    else if (n>=270 && n<360) cout << "De Madrugada!!" << endl;
  }
  return 0;
}
