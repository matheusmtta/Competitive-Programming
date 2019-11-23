/*
* Escultura a Laser
* URI Online Judge 1107
* 02/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int reservas[21];

int main(){
  int x, y;
  while(1){
    cin >> x >> y;
    if (x==0 && y== 0) break;
    int block[y], quant[y], ans=0;
    for (int i = 0; i < y; i++)
      block[i] = quant[i] = 0;
    int k = x;
    for (int i = 0; i < y; i++){
      cin >> block[i];
      if (k > block[i]) ans+=(k-block[i]);
      k = block[i];
    }
    cout << ans << endl;
  }
  return 0;
}
