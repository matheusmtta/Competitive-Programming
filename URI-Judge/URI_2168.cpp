#include <bits/stdc++.h>

using namespace std;

int mtx[101][101];
int n, aux;

int main(){
  cin >> n;
  for (int i = 0; i < n+1; i++){
    for (int j = 0; j < n+1; j++){
      cin >> mtx[i][j];
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i != n && j != n){
        if (mtx[i][j] == 1) aux++;
        if (mtx[i+1][j] == 1) aux++;
        if (mtx[i+1][j+1] == 1) aux++;
        if (mtx[i][j+1] == 1) aux++;
        if (aux >= 2) cout << 'S';
        else cout << 'U';
      }
      aux = 0;
    }
    cout << endl;
  }
  return 0;
}
