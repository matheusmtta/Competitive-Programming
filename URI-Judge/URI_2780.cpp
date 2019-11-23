/*
* Basquete de Robôs
* URI Online Judge 2780
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  if (n <= 800) cout << 1 << endl;
  else if (n > 800 && n <= 1400) cout << 2 << endl;
  else cout << 3 << endl;
}
