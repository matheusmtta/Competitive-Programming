/*
* As Moedas de Robbie
* URI Online Judge 2709
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, salto, x, ans=0;
  vector <int> moedas;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x;
    moedas.push_back(x);
  }
  cin >> salto;
  for (int i = 0; i < n; i++){
    int idx = n-1 - (salto*i);
    if (idx < 0) break;
    else ans+=moedas[idx];
  }
  //cout << ans << endl;
  if (ans < 2) {printf("Bad boy! I’ll hit you.\n"); exit(0);}
  if (ans == 2) {printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n"); exit(0);}
  for (int i = 2; i * i <= ans; i++){
    if (ans%i==0) { printf("Bad boy! I’ll hit you.\n"); exit(0);}
  }
  printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
}
