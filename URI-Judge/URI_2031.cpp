#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(0); cin.tie(0);
  int n;
  string jogador1, jogador2;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> jogador1;
    cin >> jogador2;
    if (jogador1 == "pedra" && jogador2 == "pedra") cout << "Sem ganhador" << endl;
    else if (jogador1 == "ataque" && jogador2 == "ataque") cout << "Aniquilacao mutua" << endl;
    else if (jogador1 == "papel" && jogador2 == "papel") cout << "Ambos venceram" << endl;
    else if ((jogador1 == "ataque" && jogador2 != "ataque") || (jogador1 == "pedra" && jogador2 == "papel")) cout << "Jogador 1 venceu" << endl;
    else cout << "Jogador 2 venceu" << endl;
  }
  return 0;
}
