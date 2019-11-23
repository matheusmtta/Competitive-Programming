/*
* Alarme Despertador
* URI Online Judge 1103
* 02/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;



int main(){
  int h1, h2, m1, m2;
  while(1){
    cin >> h1 >> m1 >> h2 >> m2;
    if (h1 == 0 && m1 == 0 && h2==0 && m2 == 0) break;
    if (h1 == 0) h1 = 24;
    if (h2 == 0) h2 = 24;
    int total_a = (h1*60)+m1;
    int total_b = (h2*60)+m2;
    if ((h1 > h2) || (h1 == h2 && m2 <= m1)){
      int ans = 1440-(total_a-total_b);
      cout << ans << endl;
    }
    else{
      cout << total_b-total_a << endl;
    }
  }
}
