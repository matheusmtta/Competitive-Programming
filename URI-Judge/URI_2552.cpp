#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, sum=0;
  while (cin >> n >> m){
    int mtx[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> mtx[i][j];
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (mtx[i][j] == 1) cout << 9;
        else if (mtx[i][j] == 0){
          if (i != n-1 && mtx[i+1][j] == 1) sum++;
          if (i != 0 && mtx[i-1][j] == 1) sum++;
          if (j != m-1 && mtx[i][j+1] == 1) sum++;
          if (j != 0 && mtx[i][j-1] == 1) sum++;
          cout << sum;
          sum = 0;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
