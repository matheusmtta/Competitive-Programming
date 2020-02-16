#include <bits/stdc++.h>

using namespace std;

vector <string> palavras;
int contador;

int find(string aux){
  int tam=aux.length();
  int maximum=0;
  bool help=true;
  for (int i = 0; i < palavras.size(); i++){//palavrasuntos
    help=true;
    for (int j = 0; j < tam; j++){//tamanho palavra
      if(palavras[i][j] != aux[j]) {help = false; break;}
    }
    if (!help) continue;
    contador++;
    int resp = palavras[i].length();
    maximum = max(maximum, resp);
  }
  return maximum;
}

int main(){
  int base, q;
  cin >> base;
  string aux;
  for (int i=0; i < base; i++){
    cin >> aux;
    palavras.push_back(aux);
  }
  int pesq, ans;
  cin >> pesq;
  for (int i = 0; i < pesq; i++){
    cin >> aux;
    ans = find(aux);
    if (ans) cout << contador << " " << ans << endl;
    else cout << -1 << endl;
    contador = 0;
  }
  return 0;
}
