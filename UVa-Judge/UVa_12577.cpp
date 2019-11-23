/*
* Hajj-e-Akbar
* Uva Online Judge 12577
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int k=1;
  while(1){
    string str; cin >> str;
    if (str=="*") return 0;
    else {
      cout << "Case " << k << ": ";
      if (str=="Hajj") cout << "Hajj-e-Akbar" << endl;
      else cout << "Hajj-e-Asghar" << endl;
    }
    k++;
  }
  return 0;
}
