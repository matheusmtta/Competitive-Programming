#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n;
  while (scanf("%d", &n) != EOF){
    int mtx[n][n];
    float aux;
    aux = n*1.0;
    aux = floor(aux/3);
    int m = aux;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if ((i >= aux && i <= (n-1-aux)) && (j >= aux && j <= (n-1-aux)))
          mtx[i][j] =1;
        else
          mtx[i][j] = 0;
      }
    }

    for (int i = 0; i < n; i++)
      mtx[i][i] = 2;

    int k = n-1;
    for (int i = 0; i < n; i++){
      mtx[i][k] = 3;
      k--;
    }

    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if ((i >= aux && i <= (n-1-aux)) && (j >= aux && j <= (n-1-aux)))
          mtx[i][j] =1;
      }
    }

    mtx[(int)(n*1.0/2.0)][(int)(n*1.0/2.0)] = 4;

    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        cout << mtx[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
