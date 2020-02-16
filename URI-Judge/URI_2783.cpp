#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, c, m;
  cin >> n >> c >> m;
  int carimbadas[c], compradas[m], aux=c;
  for (int i = 0; i < c; i++){
    cin >> carimbadas[i];
  }
  for (int i = 0; i < m; i++){
    cin >> compradas[i];
  }
  for (int i = 0; i < c; i++){
    for (int j = 0; j < m; j++){
      if(carimbadas[i] == compradas[j]){
        aux--;
        break;
      }
    }
  }

  cout << aux << endl;

  return 0;
}
