#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, x;
  while(cin >> n >> m){
    int notas[n];
    for (int i = 0; i < n; i++)
      cin >> notas[i];
    sort(notas, notas+n);
    for (int i = 0; i < m; i++){
      cin >> x;
      cout << notas[n-x] << endl;
    }
  }
  return 0;
}
