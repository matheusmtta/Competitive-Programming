/*
* A mudança Contínua!!
* URI Online Judge 2686
* 24/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  float op, n;
  int h, s, m;
  while(cin >> n){
    if (n == 360 || (n>= 0 && n<90)) cout << "Bom Dia!!" << endl;
    else if (n>=90 && n<180) cout << "Boa Tarde!!" << endl;
    else if (n>=180 && n<270) cout << "Boa Noite!!" << endl;
    else if (n>=270 && n<360) cout << "De Madrugada!!" << endl;
    op = (6*n)/1.5;
    h = ((int)(op/60)+6)%24;
    m = ((int)op%60);
    if (h < 10) printf("0%d:", h);
    else printf("%d:", h);
    if (m < 10) printf("0%d:00\n", m);
    else printf("%d:00\n", m);
  }
  return 0;
}
