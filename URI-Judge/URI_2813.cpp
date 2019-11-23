/*
* Evitando Chuva
* URI Online Judge 2813
* 29/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

string umbrellas[1000][1000];

int main(){
  int n, atual, casa=0, trabalho=0, aux_g_tra=0, aux_g_cas=0;
  while(cin >> n){
    atual=casa=trabalho=aux_g_cas=aux_g_tra=0;
    //getchar();
    for (int i = 0; i < n; i++){
      cin >> umbrellas[i][0];
      cin >> umbrellas[i][1];
      if (umbrellas[i][0]=="chuva"){
        aux_g_tra+=1;
        if (aux_g_cas > 0) aux_g_cas-=1;
        else casa++;
      }
      if (umbrellas[i][1]=="chuva"){
        aux_g_cas+=1;
        if (aux_g_tra > 0) aux_g_tra-=1;
        else trabalho++;
      }
    }
    cout << casa << " " << trabalho << endl;
  }
}
