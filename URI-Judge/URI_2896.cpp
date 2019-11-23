/*
* Aproveite a Oferta
* URI Online Judge 2896
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, aux, q, r, x, y;
  cin >> n;
  while(n--){
    cin >> x >> y;
    if (y > x) {cout << x << endl; continue;}
    aux = x%y;
    q = x/y;
    cout << aux+q << endl;
  }
}
