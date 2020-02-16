#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  string str;
  double saques=0, bloqueios=0, ataques=0, x, y, z, a, b, c;
  double D_saques=0, D_bloqueios=0, D_ataques=0;
  for (int i = 0; i < n; i++){
    cin >> str;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    saques+=a;
    bloqueios+=b;
    ataques+=c;
    D_saques+=x;
    D_bloqueios+=y;
    D_ataques+=z;
  }
  printf("Pontos de Saque: %.2lf %%.\n", (D_saques/saques)*100);
  printf("Pontos de Bloqueio: %.2lf %%.\n", 100*(D_bloqueios/bloqueios));
  printf("Pontos de Ataque: %.2lf %%.\n", (D_ataques/ataques)*100);
  return 0;
}
