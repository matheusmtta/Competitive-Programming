#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

using namespace std;

int memo[100][100];
int peso[100], dano[100];
int casos, tiros;
int capacidade, resistencia;

int DC(int idx, int capacity){
  if (capacity < 0) return -INF;
  if (idx==tiros) return 0;
  int & dmx = memo[idx][capacity];
  if (dmx != -1) return dmx;
  return dmx = max(DC(idx+1, capacity), dano[idx] + DC(idx+1, capacity-peso[idx]));

}

int main(){
  cin >> casos;
  while (casos--){
    cin >> tiros;
    for (int i = 0; i < tiros; i++)
      cin >> dano[i] >> peso[i];
    cin >> capacidade;
    cin >> resistencia;
    for (int i = 0; i < 100; i++){
      for (int j = 0; j < 100; j++){
        memo[i][j] = -1;
      }
    }
    int resp = DC(0, capacidade);
    if (resp >= resistencia)
      cout << "Missao completada com sucesso" << endl;
    else
      cout << "Falha na missao" << endl;
  }
}
