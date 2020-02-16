#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF){
    int mtx[n][m], t_i, t_j, p_i, p_j, x, y;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cin >> mtx[i][j];
        if (mtx[i][j] == 2) {p_i = i; p_j = j;}
        if (mtx[i][j] == 1) {t_i = i; t_j = j;}
      }
    }
    x = abs(p_i - t_i);
    y = abs(p_j - t_j);
    cout << x+y << endl;
  }
  return 0;
}
