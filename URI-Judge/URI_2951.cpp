/*
* O Retorno do Rei
* URI Online Judge 2951
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  map <char, int> runas;
  int n, m, x, ans=0, k;
  char aux;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> aux >> x;
    runas.insert({aux, x});
  }
  cin >> k;
  for (int i = 0; i < k; i++){
    cin >> aux;
    ans+=runas[aux];
  }
  cout << ans << endl;
  ans >= m ? cout << "You shall pass!" << endl : cout << "My precioooous" << endl;
}
