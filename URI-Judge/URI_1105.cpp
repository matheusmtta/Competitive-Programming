/*
* Sub Prime
* URI Online Judge 1105
* 02/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int reservas[21];

int main(){
  int n, b;
  while(1){
    cin >> b >> n;
    if (b==0 && n ==0) break;
    for (int i = 0; i < 21; i++)
      reservas[i] = 0;
    int x, aux=0;
    for (int i = 1; i <= b; i++){
      cin >> x;
      reservas[i]+=x;
    }
    //cout << "hello" << endl;
    int val, crd, deb;
    for (int i = 0; i < n; i++){
      cin >> deb >> crd >> val;
      reservas[deb]-=val;
      reservas[crd]+=val;
    }
    for (int i = 1; i <= b; i++)
      if (reservas[i] < 0) aux=1;
    aux == 1 ? cout << "N" << endl : cout << "S" << endl;
  }
}
