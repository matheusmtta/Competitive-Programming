#include <bits/stdc++.h>

using namespace std;

int mtx[1000][1000];
int n, m;

int checkSL(int i, int j){
  if (j == 0 || j == m-1) return 0;
  else if (i == 0 || i == n-1) return 0;
  for (int k = j-1; k < j+2; k++){
    if (mtx[i-1][k] != 7) return 0;
    else if (mtx[i+1][k] != 7) return 0;
  }
  if (mtx[i][j+1] != 7 || mtx[i][j-1] != 7) return 0;
  return 1;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cin >> mtx[i][j];
      }
    }

    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (mtx[i][j] == 42)
          if (checkSL(i, j) == 1) {cout << i+1 << " " << j+1 << endl; return 0;}
      }
    }

    cout << "0 0" << endl;

    return 0;
}
