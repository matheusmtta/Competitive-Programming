#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, a, b, x, y, z;
  while (cin >> n){
    cin >> a >> b;
    int mtx_a[a][n], mtx_b[b][n];
    for (int i = 0; i < a; i++)
      for (int j = 0; j < n; j++)
        cin >> mtx_a[i][j];
    for (int i = 0; i < b; i++)
      for (int j = 0; j < n; j++)
        cin >> mtx_b[i][j];

    cin >> x >> y >> z;

    if (mtx_a[x-1][z-1] > mtx_b[y-1][z-1]) cout << "Marcos" << endl;
    else if (mtx_a[x-1][z-1] < mtx_b[y-1][z-1]) cout << "Leonardo" << endl;
    else cout << "Empate" << endl;
  }
  return 0;
}
