/*
* Tamanho da Placa
* URI Online Judge 2802
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, y, m;
  while(cin >> x >> y >> m){
    for (int i = 0; i < m; i++){
      int xi, yi;
      cin >> xi >> yi;
      ( ((xi <= x && yi <= y)||( xi<=y&& yi<=x )) && xi*yi <= x*y ) ? cout << "Sim" << endl : cout << "Nao" << endl;
    }
  }
  return 0;
}
