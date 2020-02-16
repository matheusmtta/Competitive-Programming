#include <bits/stdc++.h>

using namespace std;

int mtx[10010][65];

int uniao_c(int a, int b){
  int resp=0;
  for (int i = 1; i <= 60; i++)
    resp += max(mtx[a][i], mtx[b][i]);
  return resp;
}

int instercecao_c(int a, int b){
  int resp=0;
  for (int i = 1; i <= 60; i++)
    resp += min(mtx[a][i], mtx[b][i]);
  return resp;
}

int main(){
  //ios_base :: sync_with_stdio(0); cin.tie(0);
  int T, n_conjuntos, conjunto, elemento, cases, o, a, b;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n_conjuntos);
    for (int i = 0; i < n_conjuntos; i++){
      scanf("%d", &conjunto);
      for (int j = 0; j < conjunto; j++){
        scanf("%d", &elemento);
        mtx[i][elemento] = 1;
      }
    }
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
      scanf("%d %d %d", &o, &a, &b);
      o == 1 ? cout << instercecao_c(a-1, b-1) << endl : cout << uniao_c(a-1, b-1) << endl;
    }
    for (int i = 0; i < n_conjuntos; i++)
      for (int j = 0; j < 61; j++)
        mtx[i][j] = 0;
  }
  return 0;
}
