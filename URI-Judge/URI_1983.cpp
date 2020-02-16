#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int matricula[n], max_matricula;
  float nota[n], max_nota;
  cin >> max_matricula >> max_nota;
  for (int i = 1; i < n; i++){
    cin >> matricula[i] >> nota[i];
    if (nota[i] > max_nota){
      max_matricula = matricula[i];
      max_nota = nota[i];
    }
  }
  if (max_nota >= 8)
    cout << max_matricula << endl;
  else cout << "Minimum note not reached" << endl;
  return 0;
}
